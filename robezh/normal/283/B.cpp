#include<cstdio>
#include<iostream>
using namespace std;

typedef long long ll;

const ll INF = 1e18;
const int N = 200000;
int n;
int num[200050];
ll dp[400050];

ll dfs(int i, int mode) {
	
    if(i <= 0 || i > n) return 0;
    
    int index = i+(mode-1)*N;
    if(dp[index] != -1) return dp[index];
    dp[index] = -INF;
    
    ll res;
    if(mode == 1) res = dfs(i+num[i], 2);
	else res = dfs(i-num[i], 1);
	
    return dp[index] =  (res != -INF ? num[i] + res : -INF);
}

int main() {
    fill(dp, dp+400050, -1);
    scanf("%d", &n);
    for(int i = 2; i <= n; i++) {
        scanf("%d", &num[i]);
    }
    for(int i = 1; i <= n-1; i++) {
        num[1] = i, dp[1] = -1;
        ll ans = dfs(1,1);
        ans = (ans == -INF ? -1 : ans);
        printf("%I64d\n",ans);
    }
}