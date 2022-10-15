#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
ll s[MAXN];
ll suf[MAXN],pre[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
        {
            s[i]=a[i];
            s[i]-=s[i-1];
        }
        if(s[n]&1) {puts("NO"); continue;}
        suf[n]=s[n]; suf[n-1]=s[n-1];
        for(int i=n-2;i>=1;i--) suf[i]=min(suf[i+2],s[i]);
        pre[1]=s[1];
        for(int i=2;i<=n;i++) pre[i]=min(pre[i-1],s[i]);
        bool f=false;
        if(suf[1]>=0&&suf[2]>=0&&s[n]==0) f=true;
        for(int i=1;i<=n-1;i++)
        {
            ll x=a[i+1]-a[i];
            ll val=((n-i)&1)?s[n]-2*x:s[n]+2*x;
            if(pre[i-1]>=0&&s[i]+x>=0&&suf[i+1]-2*x>=0&&(i==n-1||suf[i+2]+2*x>=0)&&val==0) f=true;
        }
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}