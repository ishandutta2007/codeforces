#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int tot,ans;
int ask(int w)
{
    tot++; 
    printf("? %lld\n",w);
    fflush(stdout);
    int x;scanf("%lld",&x);
    return x;
}
void answer(int x)
{
    printf("! %lld\n",x);
    fflush(stdout);
    return;
}
void solve(int l,int r,int x,int y)
{
    if(x==y) return;
    if(r-l<=1) return;
    int mid=(l+r)/2;
    int tmp=ask(mid);
    if(tmp!=n+1) ans=min(ans,tmp*mid);
    solve(l,mid,tmp,y); solve(mid,r,x,tmp);
}
signed main()
{
    scanf("%lld",&n);
    int l=0,r=2001*n-1;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(ask(mid)==1) r=mid; else l=mid; 
    }
    int ans=r;
    for(int i=2;i<=n;i++) 
    {
        int x=ask(r/i);
        if(x!=0) ans=min(ans,(r/i)*x);
    }
    answer(ans);
    return 0;
}