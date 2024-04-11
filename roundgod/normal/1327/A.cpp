#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        ll x=1LL*(1+2*k-1)*k/2;
        if((x-n)%2==0&&x<=n) puts("YES"); else puts("NO");
    }
    return 0;
}