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
#define MAX_N 105
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

int n;
int weights[MAX_N];
pii weightAmts[MAX_N];
int curr;
int preSums[MAX_N];

bool comp(pii a, pii b){
    if(a.s != b.s) return a.s > b.s;
    return a.f < b.f;
}

int dp[2][MAX_N][MAX_N*MAX_N];
void prepro(){
    dp[0][0][0] = 1;
    dp[0][1][weights[0]] = 1;
    FOR(i, 1, n-1){
        //cout << "doing " << i << "\n";
        F0R(k, preSums[i]+1){
            dp[i%2][0][k] = dp[(i+1)%2][0][k];
            FOR(j, 1, i+1){
                //cout << "doing " << i << " " << j << " " << k << "\n";
                dp[i%2][j][k] = dp[(i+1)%2][j][k];
                if(k >= weights[i]){
                    //cout << "adding more\n";
                    dp[i%2][j][k] += dp[(i+1)%2][j-1][k-weights[i]];
                    dp[i%2][j][k] %= MOD;
                }
            }
        }
    }
}

int choose[MAX_N][MAX_N];
void getChoose(){
    F0R(i, MAX_N){
        choose[i][0] = 1;
        choose[i][i] = 1;
    }
    FOR(i, 2, MAX_N-1){
        FOR(j, 1, i-1){
            choose[i][j] = choose[i-1][j-1] + choose[i-1][j];
            choose[i][j] %= MOD;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    getChoose();

    /*F0R(i, 10){
        F0R(j, i){
            cout << choose[i][j] << " ";
        }
        cout << "\n";
    }*/

    cin >> n;
    F0R(i, n){
        cin >> weights[i];
    }

    sort(weights, weights+n);
    preSums[0] = weights[0];
    FOR(i, 1, n-1){
        preSums[i] = preSums[i-1] + weights[i];
    }
    //cout << "gonna start prepro now\n";
    prepro();
    //cout << "wow it worked\n";

    /*F0R(i, n+1){
        F0R(j, 10){
            cout << dp[(n+1)%2][i][j] << " ";
        }
        cout << "\n";
    }*/

    weightAmts[0] = {weights[0], 1};
    
    FOR(i, 1, n-1){
        if(weights[i] == weights[i-1]){
            weightAmts[curr].s++;
        } else{
            curr++;
            weightAmts[curr] = {weights[i], 1};
        }
    }

    curr++;
    sort(weightAmts, weightAmts+curr, comp);

    /*F0R(i, curr){
        cout << weightAmts[i].f << " " << weightAmts[i].s << "\n";
    }*/

    int maxAmt = 1;
    F0R(i, curr){
        RFOR(j, weightAmts[i].s, maxAmt){
            int amtWays = dp[(n+1)%2][j][j*weightAmts[i].f];

            int expectedAmt = choose[weightAmts[i].s][j];

            if(amtWays == expectedAmt){
                maxAmt = j;
                if(curr == 2 && j == weightAmts[i].s){
                    maxAmt = n;
                }
            }
        }
    }

    cout << maxAmt << "\n";

    return 0;
}