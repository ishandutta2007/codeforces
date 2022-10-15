#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll N,c1,v1,c2,v2;
int main()
{
	scanf("%lld%lld%lld%lld%lld",&N,&v1,&v2,&c1,&c2);
	if(N/c1<=40000||N/c2<=40000)
    {
        if(N/c2<=40000) {swap(c1,c2); swap(v1,v2);}
        ll ans=0;
        for(ll i=0;i*c1<=N;i++)
            ans=max(ans,i*v1+(N-i*c1)/c2*v2);
        printf("%lld\n",ans);
        return 0;
    }
    if(v1*c2>v2*c1)
    {
        swap(v1,v2);
        swap(c1,c2);
    }
    ll ans=0;
    for(ll i=0;i<c2&&i*c1<=N;i++)
        ans=max(ans,i*v1+(N-i*c1)/c2*v2);
    printf("%lld\n",ans);
}