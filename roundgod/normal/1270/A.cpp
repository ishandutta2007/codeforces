#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k1,k2;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&k1,&k2);
        int x=0,y=0;
        for(int i=1;i<=k1;i++)
        {
            int xx;
            scanf("%d",&xx);
            x=max(x,xx);
        }
        for(int i=1;i<=k2;i++)
        {
            int xx;
            scanf("%d",&xx);
            y=max(y,xx);
        }
        if(x>y) puts("YES"); else puts("NO");
    }
    return 0;
}