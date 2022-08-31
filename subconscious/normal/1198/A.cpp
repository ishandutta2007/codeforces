#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define res(i,n) for(int i=0;i<n;++i)
#define eb emplace_back
#define mp make_pair
#define x0 fuckcjb
#define y0 fuckcxb
#define x1 fuckxjb
#define y1 fuckcjx
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=3e6+5,mod=1e9+7;
const ld eps=1e-9,inf=1e50;
int n,m,a[N],b[N];
map<int,int>p;
int main(){
    scanf("%d%d",&n,&m);m*=8;
    m=m/n;if(m>30)m=30;
    int k=1<<m;
    rep(i,n){
        int x;scanf("%d",&x);
        if(p.find(x)==p.end())p[x]=1;
        else ++p[x];
    }
    int top=0;
    for(pr r:p)a[++top]=r.nd;
    int now=0;
    int cur=top;while(cur>k)now+=a[cur],--cur;
    int ans=now;
    for(int i=2;i<=n;++i){
        now+=a[i-1];
        if(cur+i-1<=n)now-=a[cur+i-1];
        ans=min(ans,now);
    }
    printf("%d\n",ans);
    return 0;
}