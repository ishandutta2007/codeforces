#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
int main(){
    int n,k;scanf("%d%d",&n,&k);
    k=240-k;
    int ans=0;
    rep(i,1,n)if(5*i<=k){
        ++ans;k-=5*i;
    }
    printf("%d\n",ans);
    return 0;
}