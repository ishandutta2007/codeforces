#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=110000;
int n,f[N];int cnt[N],g[N],h[N],m;
int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&f[i]);
    rep(i,1,n)cnt[f[i]]++;
    rep(i,1,n)if(cnt[i]&&f[i]!=i){
        printf("-1\n");
        return 0;
    }
    rep(i,1,n)if(cnt[i]){
        ++m;h[m]=i;g[i]=m;
    }
    rep(i,1,n)if(f[i]!=i){
        g[i]=g[f[i]];
    }
    printf("%d\n",m);
    rep(i,1,n)printf("%d ",g[i]);printf("\n");
    rep(i,1,m)printf("%d ",h[i]);printf("\n");
    return 0;
}