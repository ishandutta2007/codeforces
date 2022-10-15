#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,m;
ll calc(int x)
{
    return 1LL*x*(x+1)/2;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        int zeroes=n-m;
        int cnt=zeroes%(m+1);
        ll ans=calc(n)-1LL*calc(zeroes/(m+1))*(m+1-cnt)-1LL*calc(zeroes/(m+1)+1)*cnt;
        printf("%lld\n",ans);
    }
    return 0;
}