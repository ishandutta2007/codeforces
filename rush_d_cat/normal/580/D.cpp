#include<iostream>
#include<cstdio>
using namespace std;
typedef __int64 ll;
#define min(a,b) a<b?a:b;
const int inf = 100000000;
ll n,m,k,a[20],map[20][20];
ll dp[1<<18][18],res=0;
ll lowbit(ll x){
    ll res=0;
    while(x){
        if(x&1) res++;
        x>>=1;
    }
    return res;
}
int main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) {cin>>a[i];}
    for(int i=0;i<k;i++) {int x,y,z;cin>>x>>y>>z;map[x-1][y-1]=z;}
    for(int i=0;i<n;i++) dp[1<<i][i]=a[i];
    for(int s=0;s<=(1<<n)-1;s++){
        for(int v=0;v<n;v++){
            if((1<<v)&s){
                for(int u=0;u<n;u++){
                    if(!((1<<u)&s)){
                        dp[s|(1<<u)][u]=max(dp[s][v]+map[v][u]+a[u],dp[s|(1<<u)][u]);
                    }
                }
            }
        }
    }
    for(int i=0;i<1<<n;i++){
        if(lowbit(i)>m) continue;
        for(int j=0;j<n;j++){
            if(i&(1<<j))res=max(res,dp[i][j]);
        }
    }
    cout<<res<<endl;
}