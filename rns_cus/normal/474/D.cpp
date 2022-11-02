#include<bits/stdc++.h>
using namespace std;

#define N 100010
#define mod 1000000007
int T, k, dp[N], gas[N], a, b, ans;

void pre(){
    gas[0] = 1;
    for(int i = 1; i < N; i ++){
        gas[i] = gas[i-1];
        if(i >= k) gas[i] += gas[i-k];
        gas[i] %= mod;
    }
    for(int i = 1; i < N; i ++){
        dp[i] = dp[i-1] + gas[i];
        dp[i] %= mod;
    }
}

int main(){
    scanf("%d %d", &T, &k);
    pre();
    while(T --){
        scanf("%d %d", &a, &b);
        ans = (dp[b] + mod - dp[a-1]) % mod;
        printf("%d\n", ans);
    }
}