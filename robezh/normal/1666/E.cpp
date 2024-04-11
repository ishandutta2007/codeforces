#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const int N=1e5+5,mod=998244353;
int L,n,u[N],v[N],limu[N],limv[N],ans[N];
int main() {
    scanf("%d%d",&L,&n);
    u[0]=v[0]=0;
    rep(i,n){
        int x;scanf("%d",&x);
        if(i!=n)u[i]=x;
        if(i-1!=0)v[i-1]=x;
    }
    u[n]=v[n]=L;
    int x,y;
    {
        int l=-1,r=L+1;
        while(l+1<r){
            ll mid=(l+r)/2;
            bool flag=1;
            ll mi=v[n]-n*mid;
            for(int i=n-1;~i;--i){
                mi=min(mi,v[i]-i*mid);
                if(u[i]-i*mid>mi){flag=0;break;}
            }
            if(flag)l=mid;else r=mid;
        }
        x=l;
    }
    {
        int l=-1,r=L+1;
        while(l+1<r){
            ll mid=(l+r)/2;
            bool flag=1;
            ll ma=u[n]-n*mid;
            for(int i=n-1;~i;--i){
                ma=max(ma,u[i]-i*mid);
                if(v[i]-i*mid<ma){flag=0;break;}
            }
            if(flag)r=mid;else l=mid;
        }
        y=r;
    }
    //printf("%d %d\n",x,y);
    limu[0]=limv[0]=0;
    rep(i,n)limu[i]=max(u[i],limu[i-1]+x),limv[i]=min(v[i],limv[i-1]+y);
    ans[n]=L;
    for(int i=n-1;~i;--i)
        ans[i]=max(ans[i+1]-y,limu[i]);
    rep(i,n)printf("%d %d\n",ans[i-1],ans[i]);
    return 0;
}