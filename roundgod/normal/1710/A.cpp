#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=k;i++) scanf("%d",&a[i]);
        bool f=false;
        ll cnt=0;
        bool odd=false;
        for(int i=1;i<=k;i++)
        {
            if(a[i]>=2*n) {cnt+=(a[i]/n); if(a[i]/n>2) odd=true;}
        }
        if(cnt>=m&&(odd||(m%2==0))) f=true;
        cnt=0; odd=false;
        for(int i=1;i<=k;i++)
            if(a[i]>=2*m) {cnt+=(a[i]/m); if(a[i]/m>2) odd=true;}
        if(cnt>=n&&(odd||(n%2==0))) f=true;
        if(f) puts("Yes"); else puts("No");
    }
    return 0;
}