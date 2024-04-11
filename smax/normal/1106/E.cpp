#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

#define MAXN 100005
#define MAXM 205

long long dp[MAXN][MAXM];
vector<array<int, 3>> in[MAXN], out[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i=0; i<k; i++) {
        int s, t, d, w;
        cin >> s >> t >> d >> w;
        in[s].push_back({w, d, i});
        out[t].push_back({w, d, i});
    }

    memset(dp, 127, sizeof(dp));
    for (int j=0; j<=m; j++)
        dp[1][j] = 0;

    set<array<int, 3>> st;
    for (int i=1; i<=n; i++) {
        for (auto &e : in[i])
            st.insert(e);

        int w = (!st.empty() ? (*st.rbegin())[0] : 0), d = (!st.empty() ? (*st.rbegin())[1] : i);
        for (int j=0; j<=m; j++) {
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
            dp[d+1][j] = min(dp[d+1][j], dp[i][j] + w);
        }

        for (auto &e : out[i])
            st.erase(e);
    }

    cout << dp[n+1][m] << "\n";

    return 0;
}