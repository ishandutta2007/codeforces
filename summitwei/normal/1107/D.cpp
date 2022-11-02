#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000000000LL
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define p_q priority_queue

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 5205
int n;
int grid[MN][MN];

int conv(char c){
    if(c >= '0' && c <= '9') return c-'0';
    else return c-'A'+10;
}

int dp[MN][MN]; //biggest square

bool check(int k){
    if(n % k != 0) return false;
    F0R(i, n/k){
        F0R(j, n/k){
            if(dp[i*k][j*k] % k != 0) return false;
        }
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    F0R(i, n){
        F0R(j, n/4){
            char c;
            cin >> c;
            int x;
            x = conv(c);
            //cout << x << " ";
            F0R(k, 4){
                grid[i][j*4+k] = (x & (1<<(3-k))) > 0;
            }
        }
        //cout << "\n";
    }

    /*F0R(i, n){
        F0R(j, n){
            cout << grid[i][j];
        }
        cout << "\n";
    }*/


    F0R(i, n){
        dp[i][n-1] = 1;
        dp[n-1][i] = 1;
    }
    RFOR(i, n-2, 0){
        RFOR(j, n-2, 0){
            int cur = grid[i][j];
            if(cur == grid[i+1][j] && cur == grid[i][j+1] && cur == grid[i+1][j+1]){
                dp[i][j] = min(dp[i+1][j], min(dp[i][j+1], dp[i+1][j+1]))+1;
            } else{
                dp[i][j] = 1;
            }
            //cout << dp[i][j] << " ";
        }
        //cout << "\n";
    }

    /*F0R(i, n){
        F0R(j, n){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/

    RFOR(i, n, 2){
        if(check(i)){
            cout << i << "\n";
            return 0;
        }
    }
    cout << "1\n";

    return 0;
}