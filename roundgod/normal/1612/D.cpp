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
ll a,b,x;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&a,&b,&x);
        ll g=__gcd(a,b);
        if(x%g||x>max(a,b)) {puts("NO"); continue;}
        bool f=false;
        while(a&&b)
        {
            if(a<b) swap(a,b);
            if(x==b||(x<=a&&(x%b==a%b))) {f=true; break;}
            a=a%b;
        }
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}