#include <iostream>
#include <string.h>
#include <cstring>
#include <cstdio>
using namespace std;
typedef __int64 ll;
char s[20];
ll num[20];
ll m,n;
ll dp[1<<18][102];
bool vis[1<<18][102];
ll dfs(int s,int mod){
    ll &ans=dp[s][mod];
    if(vis[s][mod]) return ans;
    vis[s][mod]=1;
    if(s==((1<<n)-1)&&mod==0) return ans=1;
    int v[10];memset(v,0,sizeof(v));
    for(int u=0;u<n;u++){
        if((num[u]==0)&&(s==0)) continue;
        if(s&(1<<u)) continue;
        if(v[num[u]]) continue;
        v[num[u]]=1;
        ans += dfs(s^(1<<u),(mod*10+num[u])%m);
    }
    return ans;
}
int main() {
    cin>>s>>m;
    n=strlen(s);
    for(int i=0;i<n;i++)
        num[i]=s[i]-'0';
    printf("%I64d\n",dfs(0,0));
    return 0;
}