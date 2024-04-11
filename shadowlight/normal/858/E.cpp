#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <pair <string, string> > res;

set <string> all;

void move(string s, string t) {
    res.push_back({s, t});
    all.erase(s);
    all.insert(t);
}

string randomWord() {
    string s = "lolkek";
    while (all.find(s) != all.end()) {
        s = "";
        for (int i = 0; i < 6; i++) {
            s += (char) (rand() % 26 + 'a');
        }
    }
    return s;
}

string toS(int x) {
    string s = "";
    while (x) {
        s += (char) (x % 10 + '0');
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

int toI(string s) {
    int x = 0;
    if (s[0] == '0') {
        return 0;
    }
    for (char c : s) {
        if (c < '0' || c > '9') {
            return 0;
        }
        x = 10 * x + c - '0';
    }
    return x;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    srand(time(NULL));
    int n;
    cin >> n;
    vector <string> a(n);
    vector <int> type(n, 0);
    vector <string> bad1, bad2;
    vector <string> free1, free2;
    int e = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> type[i];
        if (type[i]) {
            e++;
        }
        all.insert(a[i]);
    }
    vector <pair <string, int> > bad;
    for (int i = 0; i < n; i++) {
        int x = toI(a[i]);
        if (type[i] == 1) {
            if (x && x <= n) {
                if (x > e) {
                    bad1.push_back(a[i]);
                }
            } else {
                bad.push_back({a[i], 1});
            }
        } else if (x && x <= n) {
            if (x <= e) {
                bad2.push_back(a[i]);
            }
        } else {
            bad.push_back({a[i], 2});
        }
    }
    for (int i = 1; i <= n; i++) {
        string s = toS(i);
        if (all.find(s) == all.end()) {
            if (i <= e) {
                free1.push_back(s);
            } else {
                free2.push_back(s);
            }
        }
    }
    //cout << free1.size() << " " << free2.size() << " " << bad1.size() << " " << bad2.size() << "\n";
    if (!free1.size() && !free2.size() && bad1.size() && bad2.size()) {
        string s = randomWord();
        string t = bad1.back();
        bad1.pop_back();
        free2.push_back(t);
        move(t, s);
        bad.push_back({s, 1});
    }
    while (true) {
        bool fl = false;
        while (bad1.size() && free1.size()) {
            fl = true;
            string s = bad1.back();
            string t = free1.back();
            bad1.pop_back();
            free1.pop_back();
            move(s, t);
            free2.push_back(s);
        }
        while (bad2.size() && free2.size()) {
            fl = true;
            string s = bad2.back();
            string t = free2.back();
            bad2.pop_back();
            free2.pop_back();
            move(s, t);
            free1.push_back(s);
        }
        if (!fl) {
            break;
        }
    }
    for (auto p : bad) {
        int tp = p.second;
        string s = p.first;
        if (tp == 1) {
            move(s, free1.back());
            free1.pop_back();
        } else {
            move(s, free2.back());
            free2.pop_back();
        }
    }
    cout << res.size() << "\n";
    for (auto p : res) {
        cout << "move " << p.first << " " << p.second << "\n";
    }
}