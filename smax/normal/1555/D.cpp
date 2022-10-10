#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    string s;
    cin >> n >> m >> s;

    vector<vector<vector<int>>> pref(n + 1, vector<vector<int>>(3, vector<int>(3)));
    for (int i=0; i<n; i++)
        for (int j=0; j<3; j++)
            for (int k=0; k<3; k++)
                pref[i+1][j][k] = pref[i][j][k] + (s[i] - 'a' == j && i % 3 == k);

    auto query = [&] (int l, int r, int j, int k) -> int {
        return pref[r][j][k] - pref[l-1][j][k];
    };

    auto total = [&] (int l, int r, int k) -> int {
        return query(l, r, 0, k) + query(l, r, 1, k) + query(l, r, 2, k);
    };

    for (int i=0; i<m; i++) {
        int l, r;
        cin >> l >> r;

        int ret = INT_MAX;
        vector<int> perm(3);
        iota(perm.begin(), perm.end(), 0);
        do {
            int cur = 0;
            for (int k=0; k<3; k++)
                cur += total(l, r, k) - query(l, r, perm[k], k);
            ret = min(ret, cur);
        } while (next_permutation(perm.begin(), perm.end()));
        cout << ret << "\n";
    }

    return 0;
}