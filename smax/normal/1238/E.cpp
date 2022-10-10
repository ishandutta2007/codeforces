#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

int cnt[20][20] = {}, dp[1<<20];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    string s;
    cin >> n >> m >> s;

    for (int i=1; i<n; i++) {
        cnt[s[i-1]-'a'][s[i]-'a']++;
        cnt[s[i]-'a'][s[i-1]-'a']++;
    }

    memset(dp, 127, sizeof(dp));
    dp[0] = 0;
    for (int mask=0; mask<1<<m; mask++) {
        int pos = __builtin_popcount(mask);
        for (int i=0; i<m; i++)
            if (!(mask & (1 << i))) {
                int tot = 0;
                for (int j=0; j<m; j++) {
                    if (i == j)
                        continue;
                    if (mask & (1 << j))
                        tot += cnt[i][j];
                    else
                        tot -= cnt[i][j];
                }
                dp[mask | (1 << i)] = min(dp[mask | (1 << i)], dp[mask] + tot * pos);
            }
    }

    cout << dp[(1<<m)-1] << "\n";

    return 0;
}