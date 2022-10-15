#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n%2==0)
        {
            for(int i=1;i<=n-1;i++)
                for(int j=i+1;j<=n;j++)
                {
                    if(i%2==1&&j==i+1) printf("0 ");
                    else
                    {
                        if((i+j)&1) printf("1 "); else printf("-1 ");
                    }
                }
            puts("");
        }
        else
        {
            for(int i=1;i<=n-1;i++)
                for(int j=i+1;j<=n;j++)
                {
                    int x=j-i;
                    if(x*2<=n) printf("1 "); else printf("-1 ");
                }
            puts("");
        }
    }
}