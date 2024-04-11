#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,g,b;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&g,&b);
        int need=(n+1)/2;
        int turns=(need-1)/g;
        ll ans=max(1LL*n,1LL*turns*(g+b)+need-1LL*turns*g);
        printf("%lld\n",ans);
    }
    return 0;
}