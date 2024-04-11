#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=210000;
int n,m;
char a[N],b[N];
bool vis[N];
int p[N];
bool check(int s){
    memset(vis,0,sizeof vis);
    rep(i,1,s)vis[p[i]]=1;
    int d=1;
    rep(i,1,m){
        while((vis[d]||a[d]!=b[i])&&(d<=n))++d;
        if(d>n)return 0;
        ++d;
    }
    return 1;
}
int main(){
    scanf("%s",a+1);n=strlen(a+1);
    scanf("%s",b+1);m=strlen(b+1);
    rep(i,1,n)scanf("%d",&p[i]);
    int ans=0;
    int l=1;int r=n-m;
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid))ans=mid,l=mid+1;
        else r=mid;
    }
    if(check(l))ans=l;
    printf("%d\n",ans);
    return 0;
}