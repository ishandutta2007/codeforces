#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int n, pref[(1<<17)+5][26];

int solve(int l, int r, int sz, char c) {
    int ret = r - l + 1 - (pref[r][c-'a'] - pref[l-1][c-'a']);
    if (sz == n)
        return ret;
    if (l == r) {   // one char
        c--;
        if (l % 2)  // to the right
            l++, r++;
        else    // to the left
            l--, r--;
        ret += r - l + 1 - (pref[r][c-'a'] - pref[l-1][c-'a']);
        if (l % 2 == 0)
            l--, r--;
    }
//    DEBUG(l, r, sz, ret)
    sz *= 2;
    if (sz == n)
        return ret;
    if (l % (sz * 2) == 1)
        return ret + solve(l + sz, l + 2 * sz - 1, sz, c - 1);
    if (l % (sz * 2) == 1 + sz / 2)
        return ret + solve(l + sz / 2, l + sz / 2 + sz - 1, sz, c - 1);
    if (l % (sz * 2) == 1 + sz)
        return ret + solve(l - sz, l - 1, sz, c - 1);
    return ret + solve(l - sz - sz / 2, l - sz / 2 - 1, sz, c - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> n >> s;
        for (int i=1; i<=n; i++)
            for (int j=0; j<26; j++)
                pref[i][j] = pref[i-1][j] + (s[i-1] - 'a' == j);

        int depth = 0, power = 1;
        while (power < n) {
            power *= 2;
            depth++;
        }

        int ret = INT_MAX;
        for (int i=1; i<=n; i++)
            ret = min(ret, solve(i, i, 1, 'a' + depth));//, DEBUG(i, solve(i, i, 1, 'a' + depth));

        cout << ret << "\n";
    }

    return 0;
}