#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t;
ll a,b;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&a,&b);
        if(a>b) swap(a,b);
        ll g=b-a;
        if(g==0) printf("%lld %lld\n",0LL,0LL);
        else printf("%lld %lld\n",g,min(a%g,g-a%g));
    }
    return 0;
}