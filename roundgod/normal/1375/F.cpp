#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
int a,b,c;
vector<P> v;
int go(ll x)
{
    printf("%lld\n",x);
    fflush(stdout);
    int y;
    scanf("%d",&y);
    return y;
}
void solve()
{
    sort(v.begin(),v.end());
    int res=go(2*v[2].F-v[0].F-v[1].F);
    if(res==v[0].S)
    {
        go(v[2].F-v[1].F);
        exit(0);
    }
    else if(res==v[1].S)
    {
        go(v[2].F-v[0].F);
        exit(0);
    }
    else
    {
        v[2].F+=2*v[2].F-v[0].F-v[1].F;
        solve();
    }
}
int main()
{
    scanf("%d%d%d",&a,&b,&c);
    v.push_back(P(a,1)); v.push_back(P(b,2)); v.push_back(P(c,3));
    sort(v.begin(),v.end());
    puts("First");
    solve();
    return 0;
}