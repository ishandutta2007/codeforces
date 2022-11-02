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
#define MAX_N 505

#define F0R(i, a) for(int i=0; i<a; i++)

int n, m, b, mod;
int dp[2][MAX_N][MAX_N];
int numBugs[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> b >> mod;
    F0R(i, n){
        cin >> numBugs[i];
    }

    F0R(i, n){
        dp[1][i][0] = 1;
    }
    //dp[1][0][0] = 1;

    F0R(i, m){
        F0R(j, n){
            F0R(k, b+1){
                //dp[i%2][j][k] = 0;
                if(j == 0){
                    dp[i%2][j][k] = 0;
                } else{
                    dp[i%2][j][k] = dp[i%2][j-1][k];
                }

                if(numBugs[j] <= k){
                    dp[i%2][j][k] += dp[(i+1)%2][j][k-numBugs[j]];
                }

                dp[i%2][j][k] %= mod;

                /*if(dp[i%2][j][k] != 0){
                    cout << "num of ways to make " << i << " " << j << " " << k << " is " << dp[i%2][j][k] << "\n";
                }*/
            }
        }
    }

    int sum = 0;
    F0R(i, b+1){
        sum += dp[(m+1)%2][n-1][i];
        sum %= mod;
    }

    cout << sum << "\n";

    return 0;
}