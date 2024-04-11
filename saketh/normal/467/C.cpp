#include <iostream>
using namespace std;

int N, M, K;
long long v[5005], p[5005];
long long dp[5005][5005];

long long sum(int i, int j){
    return p[j] - p[i];
}

int main(){
    cin >> N >> M >> K;
    for(int i=0; i<N; i++)
        cin >> v[i];

    for(int i=0; i<N; i++)
        p[i+1] = p[i] + v[i];

    for(int j=1; j<=K; j++)
        for(int i=(N-M); i>=0; i--)
            dp[j][i] = max(dp[j][i+1], dp[j-1][i+M] + sum(i, i+M));

    cout << dp[K][0] << endl;
    return 0;
}