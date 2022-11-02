#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 1000000000
#define MOD 998244353
#define EPSILON 0.00001
#define MAX_N 505

ll horizDP[2][MAX_N][MAX_N];
ll sums[MAX_N];

int main(){
    int n, m;
    cin >> n >> m;
    
    horizDP[1][1][1] = 1;
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            for(int k=1; k<n; k++){
                if(horizDP[i%2][j][k] == 0) continue;
                horizDP[(i+1)%2][j+1][max(k, j+1)] += horizDP[i%2][j][k];
                horizDP[(i+1)%2][j+1][max(k, j+1)] %= MOD;
                horizDP[(i+1)%2][1][k] += horizDP[i%2][j][k];
                horizDP[(i+1)%2][1][k] %= MOD;
                horizDP[i%2][j][k] = 0;
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            sums[j] += horizDP[n%2][i][j];
            sums[j] %= MOD;
        }
    }
    /*for(int i=1; i<=n; i++){
        cout << "sums of " << i << " is " << sums[i] << "\n";
    }*/

    ll sum = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i*j < m){
                ll toAdd = sums[i]*sums[j];
                toAdd %= MOD;
                sum = (sum + toAdd) % MOD;
            }
        }
    }

    cout << (sum*2)%MOD << "\n";
    return 0;
}