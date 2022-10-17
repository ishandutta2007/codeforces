#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const int MOD = 998244353;
int sum(int a, int b) { return (a + b) % MOD; }
int prod(int a, int b) { return a * 1ll * b % MOD; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, K;
    cin >> N >> K;

    vi ways(N + 1);
    for (int l = 1; l <= N; l++) {
        vi dp(N + 1);
        dp[0] = 1;
        for (int i = 1; i <= N; i++) {
            for (int j = max(0, i - l); j < i; j++)
                dp[i] = sum(dp[i], dp[j]);
        }
        ways[l] = dp[N];
    }

    for (int l = N; l >= 1; l--)
        ways[l] = sum(ways[l], MOD - ways[l-1]);

    int ans = 0;
    for (int xm = 1; xm <= N; xm++) {
        for (int ym = 1; ym <= N; ym++) {
            if (xm * ym < K)
                ans = sum(ans, prod(ways[xm], ways[ym]));
        }
    }

    cout << prod(2, ans) << endl;

    return 0;
}