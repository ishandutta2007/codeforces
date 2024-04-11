#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,a,b,x,y;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&x,&y,&a,&b);
        int z=min(x,y);
        ll ans=1LL*z*min(2*a,b);
        x-=z; y-=z;
        ans+=1LL*x*a;
        ans+=1LL*y*a;
        printf("%lld\n",ans);
    }
    return  0;
}