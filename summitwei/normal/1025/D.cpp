#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 1000000000
#define MOD 998244353
#define EPSILON 0.00001
#define MAX_N 705

int N;
int vals[MAX_N];
bool dp[MAX_N][MAX_N][2];

bool hasCF[MAX_N][MAX_N];

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> vals[i];
    }

    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            if(__gcd(vals[i], vals[j]) > 1){
                hasCF[i][j] = true;
                hasCF[j][i] = true;
            }
        }
    }

    for(int i=0; i<N-1; i++){
        if(hasCF[i][i+1]){
            dp[i][i][0] = true;
            dp[i+1][i+1][1] = true;
        }
    }

    /*for(int i=0; i<N-1; i++){
        cout << i << ": " << dp[i][i][0] << " " << dp[i][i][1] << "\n";
    }*/

    for(int len=1; len<N; len++){
        for(int i=0; i<N-len; i++){
            int j=i+len;
            //third = 0, means left side (so i = left, j+1 = root)
            for(int k=i; k<=j; k++){
                if(j < N-1 && hasCF[k][j+1] && (k == i || dp[i][k-1][0]) && (k == j || dp[k+1][j][1])){
                    dp[i][j][0] = true;
                    break;
                }
            }

            for(int k=i; k<=j; k++){
                if(i > 0 && hasCF[k][i-1] && (k == i || dp[i][k-1][0]) && (k == j || dp[k+1][j][1])){
                    dp[i][j][1] = true;
                    break;
                }
            }

            //cout << i << " " << j << " 0 is" << (dp[i][j][0]?" good and 1 is":" bad and 1 is") << (dp[i][j][1]?" good\n":" bad\n");
        }
    }

    for(int i=0; i < N; i++){
        if((i == 0 || dp[0][i-1][0]) && (i == N-1 || dp[i+1][N-1][1])){
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
    return 0;
}