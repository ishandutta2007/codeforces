#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
int a[MAXN][MAXN],b[MAXN][MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                int val=0;
                if(j!=1) val^=b[i][j-1];
                if(j!=n) val^=b[i][j+1];
                if(i!=1) val^=b[i-1][j];
                if(i!=n) b[i+1][j]=val^a[i][j];
            }
        int s=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                s^=b[i][j];
        printf("%d\n",s);
    }
    return 0;
}