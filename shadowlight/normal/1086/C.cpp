#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

int n, k;
string s, a, b;
vector <int> sh, rs;

bool left_case(int pos) {
    vector <int> sh_was = sh, rs_was = rs;
//    for (int x : sh) {
//        cout << x << " ";
//    }
//    cout << "\n";
    if (rs[a[pos] - 'a'] != -1 && rs[a[pos] - 'a'] != s[pos] - 'a') {
        return false;
    }
    sh[s[pos] - 'a'] = a[pos] - 'a';
    rs[a[pos] - 'a'] = s[pos] - 'a';
    for (int i = pos + 1; i < n; i++) {
        int c = sh[s[i] - 'a'], nc = a[i] - 'a';
        //cout << c << " " << nc << "\n";
        if (sh[s[i] - 'a'] != -1) {
            if (c < nc) {
                sh = sh_was;
                rs = rs_was;
                return false;
            }
            if (c > nc) {
                return true;
            }
            continue;
        }
        for (int j = nc + 1; j < k; j++) {
            if (rs[j] == -1) {
                sh[s[i] - 'a'] = j;
                rs[j] = s[i] - 'a';
                return true;
            }
        }
        if (rs[nc] != -1) {
            sh = sh_was;
            rs = rs_was;
            return false;
        }
        sh[s[i] - 'a'] = nc;
        rs[nc] = s[i] - 'a';
    }
    return true;
}

bool right_case(int pos) {
    vector <int> sh_was = sh, rs_was = rs;
    if (rs[b[pos] - 'a'] != -1 && rs[b[pos] - 'a'] != s[pos] - 'a') {
        return false;
    }
    sh[s[pos] - 'a'] = b[pos] - 'a';
    rs[b[pos] - 'a'] = s[pos] - 'a';
    for (int i = pos + 1; i < n; i++) {
        int c = sh[s[i] - 'a'], nc = b[i] - 'a';
        if (sh[s[i] - 'a'] != -1) {
            if (c > nc) {
                sh = sh_was;
                rs = rs_was;
                return false;
            }
            if (c < nc) {
                return true;
            }
            continue;
        }
        for (int j = nc - 1; j >= 0; j--) {
            if (rs[j] == -1) {
                sh[s[i] - 'a'] = j;
                rs[j] = s[i] - 'a';
                return true;
            }
        }
        if (rs[nc] != -1) {
            sh = sh_was;
            rs = rs_was;
            return false;
        }
        sh[s[i] - 'a'] = nc;
        rs[nc] = s[i] - 'a';
    }
    return true;
}

bool solve() {
    //cout << "post\n";
    cin >> k;
   // k = rand() % 5 + 1;
    //n = rand() % 100 + 1;
    s = "";
    a = "";
    b = "";
//    for (int i = 0; i < n; i++) {
//        s += (char) (rand() % k + 'a');
//        a += (char) (rand() % k + 'a');
//        b += (char) (rand() % k + 'a');
//    }
    if (a > b) swap(a, b);
    //cout << "TEST: " << k << " " << s << " " << a << " " << b << "\n";
    cin >> s >> a >> b;
    n = s.size();
    sh.clear();
    rs.clear();
    sh.resize(k, -1);
    rs.resize(k, -1);
    for (int i = 0; i < n; i++) {
        if (sh[s[i] - 'a'] != -1) {
            int c = sh[s[i] - 'a'];
            if (c > a[i] - 'a' && c < b[i] - 'a') {
                return true;
            }
            if (c < a[i] - 'a' || c > b[i] - 'a') {
                return false;
            }
            if (a[i] == b[i]) continue;
            if (a[i] - 'a' == c) {
                return left_case(i);
            } else {
                return right_case(i);
            }
        }
        if (a[i] == b[i]) {
            if (rs[a[i] - 'a'] != -1) {
                return false;
            }
            sh[s[i] - 'a'] = a[i] - 'a';
            rs[a[i] - 'a'] = s[i] - 'a';
            continue;
        }
        for (int j = a[i] + 1 - 'a'; j < b[i] - 'a'; j++) {
            if (rs[j] == -1) {
                sh[s[i] - 'a'] = j;
                rs[j] = s[i] - 'a';
                return true;
            }
        }
        if (left_case(i)) return true;
        if (right_case(i)) return true;
        return false;
    }
    return true;
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
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        if (solve()) {
            vector <bool> exist(k, true);
            for (int x : sh) {
                if (x != -1) {
                    exist[x] = false;
                }
            }
            int last = 0;
            while (last < k && !exist[last]) {
                last++;
            }
            for (int &x : sh) {
                if (x == -1) {
                    x = last;
                    exist[last] = false;
                    while (last < k && !exist[last]) {
                        last++;
                    }
                }
            }
            string snow = "";
            for (char c : s) {
                snow += (char) (sh[c - 'a'] + 'a');
            }
            //cout << snow << "\n";
            assert(snow >= a && snow <= b);
            cout << "YES\n";
            for (int x : sh) {
                assert(x != -1);
                cout << (char) (x + 'a');
            }
            cout << "\n";
        } else {
            cout << "NO\n";
//            vector <int> p(k);
//            iota(p.begin(), p.end(), 0);
//            do {
//                string sa = "";
//                for (int i = 0; i < n; i++) {
//                    sa += (char) (p[s[i] - 'a'] + 'a');
//                }
//                assert(sa < a || sa > b);
//            } while (next_permutation(p.begin(), p.end()));
        }
    }
}