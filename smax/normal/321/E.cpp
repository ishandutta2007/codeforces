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

#define MAXN 4001
#define MAXK 801

const long long INF = 1e18;

int u[MAXN][MAXN];
long long dp[MAXK][MAXN];

int cost(int l, int r) {
    return (u[r][r] - (l > 0 ? u[r][l-1] + u[l-1][r] - u[l-1][l-1] : 0)) / 2;
}

void solve(int k, int l, int r, int optl, int optr) {
    if (l > r)
        return;

    int mid = (l + r) / 2;
    pair<long long, int> best{INF, -1};
    for (int i=optl; i<=min(mid, optr); i++)
        best = min(best, {(i > 0 ? dp[k-1][i-1] : 0) + cost(i, mid), i});

    dp[k][mid] = best.first;
    solve(k, l, mid-1, optl, best.second);
    solve(k, mid+1, r, best.second, optr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) {
            cin >> u[i][j];
            if (i > 0) u[i][j] += u[i-1][j];
            if (j > 0) u[i][j] += u[i][j-1];
            if (i > 0 && j > 0) u[i][j] -= u[i-1][j-1];
        }

    for (int i=0; i<n; i++)
        dp[0][i] = INF;
    for (int i=1; i<=k; i++)
        solve(i, 0, n-1, 0, n-1);

    cout << dp[k][n-1] << "\n";

    return 0;
}