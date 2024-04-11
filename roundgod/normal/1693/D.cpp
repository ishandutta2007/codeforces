#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define inc sbcjb
#define dec cjbsb
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],p[MAXN];
deque<int> inc,dec; 
int ans[MAXN];
void go(int x)
{
    int inc=-INF,dec=INF;
    ans[x]=n;
    for(int i=x;i<=n;i++)
    {
        if(p[i]>inc&&p[i]<dec)
        {
            if(i==n||p[i]<p[i+1]) inc=p[i]; else dec=p[i];
        }
        else if(p[i]>inc) inc=p[i];
        else if(p[i]<dec) dec=p[i];
        else {ans[x]=i-1; return;}
    }
}
void solve(int l,int r)
{
    if(l+1>=r) return;
    if(ans[l]==ans[r]) {for(int i=l+1;i<r;i++) ans[i]=ans[l]; return;}
    int mid=(l+r)/2;
    go(mid);
    solve(l,mid); solve(mid,r);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    go(1); ans[n]=n;
    solve(1,n);
    ll res=0;
    for(int i=1;i<=n;i++) res+=(ans[i]-i+1);
    printf("%lld\n",res);
    return 0;
}