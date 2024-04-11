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
ll q,l,r,d;
int main()
{
    scanf("%lld",&q);
    for(ll i=0;i<q;i++)
    {
        scanf("%lld%lld%lld",&l,&r,&d);
        if(l>d) printf("%lld\n",d);
        else
        {
            ll rem=d-r%d;
            printf("%lld\n",r+rem);
        }
    }
    return 0;
}