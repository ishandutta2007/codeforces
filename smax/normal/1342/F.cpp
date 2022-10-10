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

const int INF = 1e9;

int a[15], sum[1 << 15], dp[16][16][1 << 15];
pair<int, int> pred[16][16][1 << 15];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> a[i];

        for (int mask=0; mask<1<<n; mask++) {
            sum[mask] = 0;
            for (int i=0; i<n; i++)
                if (mask >> i & 1)
                    sum[mask] += a[i];
        }

        for (int cnt=0; cnt<=n; cnt++)
            for (int pos=0; pos<=n; pos++)
                for (int mask=0; mask<1<<n; mask++)
                    dp[cnt][pos][mask] = INF;
        dp[0][0][0] = 0;
        for (int cnt=0; cnt<n; cnt++)
            for (int pos=0; pos<n; pos++)
                for (int mask=0; mask<1<<n; mask++)
                    if (dp[cnt][pos][mask] < INF) {
                        int left = mask ^ ((1 << n) - 1);
                        for (int sub=left; sub>0; sub=(sub-1)&left)
                            if (sub >> pos > 0 && sum[sub] > dp[cnt][pos][mask]) {
                                int npos = __builtin_ctz(sub >> pos) + pos + 1;
                                if (dp[cnt+1][npos][mask|sub] > sum[sub]) {
                                    dp[cnt+1][npos][mask|sub] = sum[sub];
                                    pred[cnt+1][npos][mask|sub] = {pos, mask};
                                }
                            }
                    }

        for (int cnt=n; cnt>0; cnt--)
            for (int pos=1; pos<=n; pos++) {
                int mask = (1 << n) - 1;
                if (dp[cnt][pos][mask] < INF) {
                    vector<pair<int, int>> ret;
                    while (cnt > 0) {
                        auto [npos, nmask] = pred[cnt][pos][mask];
                        int sub = mask ^ nmask;
                        for (int i=0; i<n; i++)
                            if (sub >> i & 1 && i + 1 != pos)
                                ret.emplace_back(i + 1, pos);
                        cnt--;
                        pos = npos;
                        mask = nmask;
                    }
                    cout << ret.size() << "\n";
                    for (auto [i, j] : ret) {
                        cout << i << " " << j << "\n";
                        for (auto &[ii, jj] : ret) {
                            if (i < ii) ii--;
                            if (i < jj) jj--;
                        }
                    }
                    goto done;
                }
            }
        done:;
    }

    return 0;
}