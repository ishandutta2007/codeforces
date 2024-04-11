#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first 
#define S second 
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
char str[MAXN];
int sum[6][MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",str+1);
    for(int k=0;k<3;k++)
        for(int i=1;i<=n;i++)
            sum[k][i]=sum[k][i-1]+(str[i]!='a'+(i+k)%3);
    for(int k=0;k<3;k++)
        for(int i=1;i<=n;i++)
            sum[k+3][i]=sum[k+3][i-1]+(str[i]!='a'+((k-i)%3+3)%3);
    for(int i=0;i<m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int ans=INF;
        for(int j=0;j<6;j++) ans=min(ans,sum[j][r]-sum[j][l-1]);
        printf("%d\n",ans);
    }
    return 0;
}