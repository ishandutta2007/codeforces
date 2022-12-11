#include <bits/stdc++.h>

using namespace std;

#define forn(a, b) for (int a = 0; (a) < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))

typedef long long ll;
typedef long double ldb;

const ldb EPS = 1e-8;
const int MAXN = 1e5+100;
const int MAXP = 11;
const int MAXA = 4;

struct ftree {
        vector<int> t;
        void init(int n) {
                t.resize(n, 0);
        }
        void inc(int x) {
                for(; x < t.size(); x = (x | (x + 1))) {
                        t[x]++;
                }
        }
        void dec(int x) {
                for(; x < t.size(); x = (x | (x + 1))) {
                        t[x]--;
                }
        }
        int get(int x) {
                int sum = 0;
                for (;x >= 0; x = (x & (x + 1)) - 1) {
                        sum += t[x];
                }
                return sum;
        }
        int get(int l, int r) {
                return get(r) - get(l - 1);
        }
};
ftree a[MAXA][MAXP][MAXP];
char getnum(char c) {
        if (c == 'A')
                return 0;
        if (c == 'C')
                return 1;
        if (c == 'G')
                return 2;
        if (c == 'T')
                return 3;
        assert(false);
}

int main() {
#ifdef LOCAL
        freopen("b.in", "r", stdin);
        //freopen("", "w", stdout);
#endif
        cin.sync_with_stdio(false);
        string s;
        int q;
        cin >> s;
        forn(i, s.length()) {
                s[i] = getnum(s[i]);
//                cerr << int(s[i]) << '\n';
        }
        for (int p = 1; p < MAXP; ++p) {
                forn(j, MAXA) {
                        forn(k, p) {
                                a[j][p][k].init((s.length() + p - 1)/p);
                        }
                }
                forn(i, s.length()) {
                        //cerr << "inc " << int(s[i]) << ' ' << p << ' ' << i % p << ' ' << i / p << '\n';
                        a[s[i]][p][i % p].inc(i/p);
                }
        }

        cin >> q;
        forn(i, q) {
                int t;
                cin >> t;
                if (t == 1) {
                        int x;
                        char c;
                        cin >> x >> c;
                        x--;
                        c = getnum(c);
                        char pr = s[x];
                        s[x] = c;

                        for (int p = 1; p < MAXP; ++p) {
                                int k = x % p;
                                int j = x/ p;
                                a[c][p][k].inc(j);
                                a[pr][p][k].dec(j);
                        }
                } else {
                        int l, r;
                        string e;
                        cin >> l >> r >> e;
                        int p = e.length();
                        l--, r--;
                        int ans = 0;
                        if (r - l + 1 <= p) {
                                for (int j = l; j <= r; ++j) {
                                        if (getnum(e[j - l]) == s[j]) {
                                                ans++;
                                        }
                                }
                        } else {
                                forn(j, p) {
                                        int k = (j + l) % p;
                                        ans += a[getnum(e[j])][p][k].get((l - k + p - 1) / p, (r - k) /p);
                                        //cerr << "T " << j << ' ' << ans << '\n';
                                        //cerr << p << ' ' << k << ' ' << (l - k + p - 1) / p << ' ' << (r - k) / p << '\n';
                                        //cerr << ans << '\n';
                                }
                        }
                        cout << ans << '\n';
                }
        }
        
        return 0;
}