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

bool dp[200005][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        map<int, int> mp;
        for (int i=0; i<m; i++) {
            int r, c;
            cin >> r >> c;
            r--;
            mp[c] |= 1 << r;
        }
        mp[n+1] = 3;

        m = mp.size();
        for (int i=0; i<=m; i++)
            for (int j=0; j<3; j++)
                dp[i][j] = false;
        dp[0][0] = true;
        int i = 0;
        for (auto it=mp.begin(); it!=mp.end(); it++) {
            auto p = *it;
            DEBUG(p)
            int pred = it == mp.begin() ? 0 : prev(it)->first;
            // for (int j=0; j<3; j++)
            //     DEBUG(j, dp[i][j])
            for (int j=0; j<3; j++) {
                if (p.second == 3) {
                    // if (p.first <= n) {
                    //     cout << "NO\n";
                    //     goto done;
                    // }
                    if (j == 0)
                        dp[i+1][j] |= dp[i][j];
                } else {
                    assert(p.second != 0);
                    if (j == 0) {
                        // if (j == 0 && pred != 0 && p.first - pred == 1) {
                        //     continue;
                        // }
                        dp[i+1][p.second^3] |= dp[i][j];
                    } else {
                        if (j == p.second) {
                            if ((p.first - pred) % 2 == 0) {
                                dp[i+1][0] |= dp[i][j];
                            }
                        } else {
                            if ((p.first - pred) % 2 == 1) {
                                dp[i+1][0] |= dp[i][j];
                            }
                        }
                    }
                }
            }
            i++;
        }
        cout << (dp[m][0] ? "YES" : "NO") << "\n";
    }

    return 0;
}