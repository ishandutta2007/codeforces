#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t;
ll x,y;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&x,&y);
        ll d=x-y;
        if(d==1) puts("NO"); else puts("YES");
    }
    return 0;
}