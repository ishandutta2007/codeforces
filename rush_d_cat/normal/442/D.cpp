#include <iostream>
#include <vector>
using namespace std;
const int N=1000000+10;
vector<int> g[N];
int n,par[N],mx[N][2],dp[N];
int main() {
    scanf("%d",&n); n++;
    for(int i=2;i<=n;i++){
        scanf("%d",&par[i]); g[par[i]].push_back(i);
    }
    par[1]=0;mx[1][0]=mx[1][1]=0;
    for(int i=2;i<=n;i++){
        int now=i;
        while(par[now]){
            int tmp=max(mx[now][0],mx[now][1]+1);
            if(tmp<=dp[now])break;
            dp[now]=tmp;
            if(dp[now]>mx[par[now]][0]) mx[par[now]][0]=dp[now];
            else if(dp[now]>mx[par[now]][1]) mx[par[now]][1]=dp[now];
            now=par[now];
            //printf("now=%d, mx0=%d, mx1=%d, dp=%d\n", now,mx[now][0],mx[now][1],dp[now]);
        }
        printf("%d\n", max(mx[1][0],mx[1][1]));
    }
}