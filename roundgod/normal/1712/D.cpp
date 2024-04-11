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
int t,n,k,a[MAXN],b[MAXN];
bool check(int x)
{
    int cnt=0;
    for(int i=1;i<=n;i++) b[i]=a[i];
    for(int i=1;i<=n;i++) if(b[i]*2<x) {cnt++; b[i]=INF+1;}
    int need=2;
    for(int i=1;i<=n-1;i++) need=min(need,(b[i]<x?1:0)+(b[i+1]<x?1:0));
    return cnt+need<=k;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int l=0,r=INF+1;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if(check(mid)) l=mid; else r=mid;
        }
        printf("%d\n",l);
    }
    return 0;
}