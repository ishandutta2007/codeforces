#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_M 1005
#define MAX_N 105

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)

int N, M;
int c[MAX_N];
double dp[2][MAX_N*MAX_M];
double sums[2][MAX_N*MAX_M];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int score = 0;

    cin >> N >> M;
    if(M == 1){
        cout << 1 << "\n";
        return 0;
    }
    F0R(i, N){
        cin >> c[i];
        score += c[i];
    }

    FOR(i, 1, M){
        if(i != c[0]){
            dp[0][i] = 1.0/(M-1);
        }
        sums[0][i] = sums[0][i-1] + dp[0][i];
        //cout << "dp " << 0 << " " << i << " is " << dp[0][i] << "\n";
        //cout << "sums " << 0 << " " << i << " is " << sums[0][i] << "\n";
    }
    FOR(i, M+1, M*N){
        sums[0][i] = 1;
    }

    FOR(i, 1, N-1){
        FOR(j, 1, M*N){
            dp[i%2][j] = (sums[(i+1)%2][j-1] - sums[(i+1)%2][max(j-M-1, 0)] - dp[(i+1)%2][max(j-c[i], 0)]) / (M-1);
            //cout << "dp " << i << " " << j << " is " << dp[i%2][j] << "\n";
            sums[i%2][j] = sums[i%2][j-1] + dp[i%2][j];
            //cout << "sums " << i << " " << j << " is " << sums[i%2][j] << "\n";
        }
    }

    double prob = 0;
    FOR(i, 1, score-1){
        prob += dp[(N+1)%2][i];
    }

    double ans = (M-1)*prob;
    cout << setprecision(12) << ans+1 << "\n";

    return 0;
}