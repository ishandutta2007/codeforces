#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
ll a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        ll s=1;
        for(int i=1;i<=n;i++)
        {
            while(a[i]%2==0) a[i]/=2,s=s*2;
        }
        sort(a+1,a+n+1);
        a[n]*=s;
        ll sum=0;
        for(int i=1;i<=n;i++) sum+=a[i];
        printf("%lld\n",sum);
    }
    return 0;
}