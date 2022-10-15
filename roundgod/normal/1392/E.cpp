#include<bits/stdc++.h>
#define MAXN 30
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,x,y;
ll k;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i&1) printf("0 ");
            else printf("%lld ",(1LL<<(i+j-3)));
        }
        printf("\n");
        fflush(stdout);
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%lld",&k);
        x=1; y=1;
        printf("%d %d\n",x,y);
        fflush(stdout);
        for(int j=0;j<2*(n-1);j++)
        {
            if(k&(1LL<<j))
            {
                if(x&1) x++; else y++;
            }
            else
            {
                if(x&1) y++; else x++;
            }
            printf("%d %d\n",x,y);
            fflush(stdout);
        }
    }
    return 0;
}