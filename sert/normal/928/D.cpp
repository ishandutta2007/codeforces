#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ld, ld> pl;

const int N = 3e5 + 10;
const ld EPS = 1e-9;
const ll INF = 1e9 + 10;

int solveTL(string &s) {
    int n = s.size();
    int ans = s.size();
    for (int i = 0; i < n; i++) {
        if (!isalpha(s[i]))
            s[i] = ' ';
    }
    map <string, int> m1, m2;
    vector <string> v;
    string cur;
    for (int i = 0; i < n; i++) {
        cur = "";
        while (i < n && isalpha(s[i])) {
            cur += s[i];
            i++;
        }
        if (cur.size())
            v.pb(cur);
    }

    for (auto t: v) {
        string cur = "";
        bool fnd = false;
        int l = -1, r = -1;
        for (int i = 0; i < t.size(); i++) {
            cur += t[i];
            if (l == -1 && m2.count(cur) && m2[cur] == 1)
                l = i;
            if (m1.count(cur) && m1[cur] == 1)
                r = i;
        }
        if (r != -1 && l != -1)
            ans -= max(0, r - l - 1);
        if (!m1.count(t))
            for (int i = 1; i <= t.size(); i++)
                m2[t.substr(0, i)]++;
        m1[t] = 1;
    }
    return ans;
}

int cur;
int ch[N][26];
bool term[N];
int cntCh[N];
int h1, h2;

void add(int v, string &s, int i) {
    //cout << v << " " << s << " " << cntCh[v] << " " << term[v] << endl;
    if (i < s.size() && ch[v][s[i] - 'a'] == -1) {
        ch[v][s[i] - 'a'] = cur++;
        cntCh[cur - 1] = 0;
    }
    if (cntCh[v] == 1 && h1 == -1)
        h1 = i;
    if (term[v])
        h2 = i;
    if (i == s.size()) {
        if (!term[v])
            cntCh[v]++;
        term[v] = true;
        return;
    }
    add(ch[v][s[i] - 'a'], s, i + 1);
    cntCh[v] = term[v];
    for (int i = 0; i < 26; i++)
        if (ch[v][i] != -1 && cntCh[ch[v][i]] != -1)
            cntCh[v] += cntCh[ch[v][i]];
}

int solveOK(string &s) {
    cur = 1;
    int n = s.size();
    for (int i = 0; i < n; i++)
        if (!isalpha(s[i]))
            s[i] = ' ';
    int ans = n;
    fill(cntCh, cntCh + n + 5, -1);
    cntCh[0] = 0;
    fill(term, term + n + 5, false);
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j < 26; j++)
            ch[i][j] = -1;

    vector <string> v;
    string cur;
    for (int i = 0; i < n; i++) {
        cur = "";
        while (i < n && isalpha(s[i])) {
            cur += s[i];
            i++;
        }
        if (cur.size())
            v.pb(cur);
    }

    for (auto t: v) {
        h1 = -1, h2 = -1;
        add(0, t, 0);
        //cout << h1 << " " << h2 << endl;
        if (h1 != -1 && h2 != -1) {
            ans -= max(0, h2 - max(1, h1) - 1);
        }
    }
    return ans;
}

void stress2(int cnt) {
    int tested = 0;
    for (int i = 0; i < 700; i++) {
        tested++;
        string s;
        string t;
        int last = 3;
        while (s.size() < 600) {
            while (t.size() < last + rand() % 20)
                t += (char)(rand() % 26 + 'a');
            s += t;
            last = t.size();
            s += ' ';
        }
        int t1 = solveTL(s);
        int t2 = solveOK(s);
        if (t1 != t2) {
            cout << "ERROR\n";
            cout << t1 << " " << t2 << endl;
            cout << s << endl;
            assert(false);
            return;
        }
        if (tested % 100 == 0)
            cout << tested << " " << s.size() << " " << t1 << " " << t2 << endl;
    }
}

void stress3(int cnt) {
    int tested = 0;
    for (int i = 0; i < 700; i++) {
        tested++;
        string s;
        string t;
        int last = 3;
        while (s.size() < 600) {
            while (t.size() < last + rand() % 20)
                t += (char)(rand() % 26 + 'a');
            for (int i = 0; i < 1 + rand() % 6; i++)
                s += t;
            last = t.size();
            s += ' ';
        }
        int t1 = solveTL(s);
        int t2 = solveOK(s);
        if (t1 != t2) {
            cout << "ERROR\n";
            cout << t1 << " " << t2 << endl;
            cout << s << endl;
            assert(false);
            return;
        }
        if (tested % 100 == 0)
            cout << tested << " " << s.size() << " " << t1 << " " << t2 << endl;
    }
}

void stress() {
    for (int i = 2; i <= 20; i++)
        stress3(i);
    for (int i = 2; i <= 20; i++)
        stress2(i);
}

void testMax() {
    string s;
    for (int i = 0; i < N - 10; i++)
        if (rand() % 25)
            s += (char)('a' + rand() % 26);
        else
            s += ' ';
    cout << (ld)clock() / CLOCKS_PER_SEC << endl;
    cout << solveOK(s) << endl;
    cout << (ld)clock() / CLOCKS_PER_SEC << endl;
}

int main() {
    //stress();
    //testMax();
//    freopen("a.in", "w", stdout);
//    string s;
//    for (int i = 0; i < 20 - 10; i++)
//        if (rand() % 25)
//            s += (char)('a' + rand() % 26);
//        else
//            s += ' ';
//    cout << s;

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    string s, cur;
    while (getline(cin, cur)) {
        s += cur + " ";
    }
    //cout << solveTL(s) << endl;
    cout << solveOK(s) << endl;
}