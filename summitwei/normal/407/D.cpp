#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000009
#define EPSILON 0.00001
#define MAX_N 405
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define p_q priority_queue

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

int N, M;
int ans;
int grid[MAX_N][MAX_N];
//int dp[MAX_N][MAX_N][MAX_N];
int dp[MAX_N][MAX_N][2];

int nextReps[MAX_N]; //for a pair of y-coords, this stores the first break instance
int numTimes[MAX_N*MAX_N];
void getReps(int l, int r){
    int bottom = 0;
    F0R(i, M){
        if(grid[l][i] == grid[r][i]){
            while(bottom < i){
                numTimes[grid[l][bottom]]--;
                numTimes[grid[r][bottom]]--;
                nextReps[bottom] = i;

                bottom++;
            }
            nextReps[bottom] = i;
            bottom++;
        } else{
            int a = grid[l][i];
            int b = grid[r][i];
            
            numTimes[a]++;
            numTimes[b]++;

            while(numTimes[a] >= 2 || numTimes[b] >= 2){
                numTimes[grid[l][bottom]]--;
                numTimes[grid[r][bottom]]--;
                nextReps[bottom] = i;

                bottom++;
            }
        }
    }

    while(bottom < M){
        numTimes[grid[l][bottom]]--;
        numTimes[grid[r][bottom]]--;
        nextReps[bottom] = M;

        bottom++;
    }
}

void bcase(int x){
    int bottom = 0;
    F0R(i, M){
        int a = grid[x][i];
        
        numTimes[a]++;
        
        while(numTimes[a] >= 2){
            numTimes[grid[x][bottom]]--;
            //nextReps[bottom] = i;
            dp[x][bottom][0] = i;
            ans = max(ans, i-bottom);

            bottom++;
        }
    }

    while(bottom < M){
        numTimes[grid[x][bottom]]--;
        //nextReps[bottom] = M;
        dp[x][bottom][0] = M;
        ans = max(ans, M-bottom);

        bottom++;
    }
}

int main(){
    cin >> N >> M;

    ans = 0;

    F0R(i, N){
        F0R(j, M){
            cin >> grid[i][j];
        }
    }

    F0R(i, N){
        bcase(i);
    }

    /*F0R(i, N){
        F0R(j, M){
            cout << dp[i][j][0] << " ";
        }
        cout << "\n";
    }*/

    FOR(i, 1, N-1){
        F0R(j, N-i){
            //j to i+j

            getReps(j, i+j);
            F0R(k, M){
                dp[j][k][i%2] = min(min(dp[j][k][(i+1)%2], dp[j+1][k][(i+1)%2]), nextReps[k]);
                //cout << i << " " << j << " " << k << " " << dp[j][k][i%2] << "\n";
                ans = max(ans, (i+1)*(dp[j][k][i%2]-k));
            }
        }
    }

    /*getReps(0, 1);
    F0R(i, M){
        cout << nextReps[i] << " ";
    }*/

    cout << ans << "\n";

    return 0;
}