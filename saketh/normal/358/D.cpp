#include<iostream>
#include<sstream>
using namespace std;

int N, dp[3005][2];
int a[3005], b[3005], c[3005];

int main(){
    cin >> N;
    for(int n=0; n<N; n++)
        cin >> a[n];
    for(int n=0; n<N; n++)
        cin >> b[n];
    for(int n=0; n<N; n++)
        cin >> c[n];
        
    dp[0][0] = a[0];
    dp[0][1] = b[0];
        
    for(int n = 1; n < N; n++){
        dp[n][1] = max(dp[n-1][0] + c[n], dp[n-1][1] + b[n]);
        dp[n][0] = max(dp[n-1][0] + b[n], dp[n-1][1] + a[n]);
    }
    
    cout << dp[N-1][0] << endl;
        
    return 0;
}