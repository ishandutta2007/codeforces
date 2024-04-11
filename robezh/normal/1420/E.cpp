#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = 82, INF = (int)1e9;


int n, m;
int a[N];
int loc[N];
int dp[N][N][N * (N - 1) / 2 + 1];
int C2[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < N; i++) C2[i] = i * (i - 1) / 2;
    rep(i, 1, n + 1) {
        cin >> a[i];
        if(a[i]) loc[++m] = i;
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = 0;
    for(int k = 1; k <= m; k++) {
        for(int i = 1; i <= n; i++) {
                for(int la = 0; la < i; la++) {
                    int di = abs(loc[k] - i);
                    for(int od = di; od <= (n - 1) * n / 2; od++) {
                        dp[k][i][od] = min(dp[k][i][od], dp[k - 1][la][od - di] + C2[i - la - 1]);
                    }
                }
        }
    }

    int res = INF;
    for(int od = 0; od <= (n - 1) * n / 2; od++) {
        for(int i = 0; i <= n; i++) {
            res = min(res, dp[m][i][od] + C2[n - i]);
        }
        cout << C2[n - m] - res << ' ';
    }


}