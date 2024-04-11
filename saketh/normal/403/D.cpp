#include<iostream>
using namespace std;

const long long MOD = 1000000007;
long long fact[1005];
long long pasc[1005][1005];
long long dp[1005][1005];
long long lemon[1005][1005];

int main(){
    fact[0] = 1;
    for(int i=1; i<=1000; i++)
        fact[i] = (fact[i-1]*i)%MOD;

    pasc[0][0] = 1;
    for(int n=1; n<=1000; n++)
        for(int r=0; r<=n; r++)
            pasc[n][r] = 
                (pasc[n-1][r]+pasc[n-1][r-1])%MOD;
    
    dp[0][0] = 1;
    for(int k=1; k<=1000; k++)
        for(int s=0; s<=1000; s++)
            for(int f=0; f<=s/k; f++)
                dp[k][s] = (dp[k][s] + dp[k-1][s-f*k])%MOD;
                
    for(int n=1; n<=1000; n++)
        for(int k=1; k<=1000; k++){
            int k2 = k*(k-1)/2;
            for(int s=k2; s<=n; s++){
                long long val = dp[k][s-k2];
                val = (val * fact[k])%MOD;
                val = (val * pasc[n-s][k])%MOD;
                lemon[n][k] = (lemon[n][k]+val)%MOD;
            }
        }
        
    int N, k, n;
    for(cin >> N; N; N--){
        cin >> n >> k;
        cout << lemon[n][k] << endl;
    }
    return 0;
}