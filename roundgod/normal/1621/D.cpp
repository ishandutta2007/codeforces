#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
int c[MAXN][MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=2*n;i++)
            for(int j=1;j<=2*n;j++)
                scanf("%d",&c[i][j]);
        ll sum=0;
        for(int i=n+1;i<=2*n;i++)
            for(int j=n+1;j<=2*n;j++)
                sum+=c[i][j];
        ll res=INF;
        for(int i=1;i<=n;i++)
            for(int j=n+1;j<=2*n;j++)
            {
                if(i!=1&&i!=n) continue;
                if(j!=n+1&&j!=2*n) continue;
                ll up=0,down=0,left=0,right=0;
                for(int k=1;k<i;k++) up+=c[k][j];
                for(int k=i+1;k<=n;k++) down+=c[k][j];
                for(int k=n+1;k<j;k++) left+=c[i][k];
                for(int k=j+1;k<=2*n;k++) right+=c[i][k];
                res=min(res,min(up,down)+min(left,right)+c[i][j]);
            }
        for(int i=n+1;i<=2*n;i++)
            for(int j=1;j<=n;j++)
            {
                if(i!=n+1&&i!=2*n) continue;
                if(j!=1&&j!=n) continue;
                ll up=0,down=0,left=0,right=0;
                for(int k=n+1;k<i;k++) up+=c[k][j];
                for(int k=i+1;k<=2*n;k++) down+=c[k][j];
                for(int k=1;k<j;k++) left+=c[i][k];
                for(int k=j+1;k<=n;k++) right+=c[i][k];
                res=min(res,min(up,down)+min(left,right)+c[i][j]);
            }
        sum+=res;
        printf("%lld\n",sum);
    }
    return 0;
}