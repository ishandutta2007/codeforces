#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN],b[MAXN];
int sa[MAXN],sb[MAXN];
bool check(int x)
{
    int k=(n+x)/4;
    return sa[n]+x*100-sa[k]>=sb[n]-(k>x?sb[k-x]:0);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        for(int i=1;i<=n;i++) sa[i]=sa[i-1]+a[i];
        for(int i=1;i<=n;i++) sb[i]=sb[i-1]+b[i];
        int l=-1,r=3*n+1;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if(check(mid)) r=mid; else l=mid;
        }
        printf("%d\n",r);
    }
    return 0;
}