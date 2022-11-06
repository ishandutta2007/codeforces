#include<bits/stdc++.h>
#define maxn 230400

using namespace std;
typedef long long ll;

ll n,query,k;

ll solve(ll x,ll y,ll z)
{
    if (z==0){
        if (y&1) return (y+1)/2;
        else return (x+1)/2+solve(x/2,y/2,x%2);
    }
    else{
        if (y&1) return x/2+solve((x+1)/2,(y+1)/2,(x+1)%2);
        else return y/2;
    }
}

int main()
{
    scanf("%lld%lld",&n,&query);
    while (query--)
    {
        scanf("%lld",&k);
        printf("%lld\n",solve(n,k,0));
    }
    return 0;
}