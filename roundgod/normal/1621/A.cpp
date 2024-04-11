#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        if(k*2-1>n) puts("-1");
        else
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                    if(i==j&&(i&1)&&(i<=2*k-1)) printf("R"); else printf(".");
                puts("");
            }
        }
    }    
    return 0;
}