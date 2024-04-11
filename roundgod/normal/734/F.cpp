#include<bits/stdc++.h>
#define MAXLOGN 32
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],b[MAXN],c[MAXN];
int cnt[MAXLOGN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    ll sum=0;
    for(int i=1;i<=n;i++) sum+=(b[i]+c[i]);
    if(sum%(2*n))
    {
        puts("-1");
        return 0;
    }
    sum/=(2*n);
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++)
    {
        ll d=(b[i]+c[i]-sum);
        if(d<0||(d%n))
        {
            puts("-1");
            return 0;
        }
        a[i]=d/n;
        for(int j=0;j<30;j++) cnt[j]+=((a[i]>>j)&1);
    }
    bool f=true;
    for(int i=1;i<=n;i++)
    {
        ll x=0,y=0;
        for(int j=0;j<30;j++)
        {
            y+=1LL*(1<<j)*n;
            if(a[i]&(1<<j)) x+=1LL*(cnt[j])*(1<<j);
            else y-=1LL*(n-cnt[j])*(1<<j);
        }
        if(x!=b[i]||y!=c[i]) f=false;
    }
    if(!f) puts("-1");
    else for(int i=1;i<=n;i++) printf("%d ",a[i]);
    return 0;
}