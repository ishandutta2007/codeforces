#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,a,b,c,d;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int ans=min(a,b)*min(c,d);
        ans=max(ans,min(a,c)*min(b,d));
        ans=max(ans,min(a,d)*min(b,c));
        printf("%d\n",ans);
    }
    return 0;
}