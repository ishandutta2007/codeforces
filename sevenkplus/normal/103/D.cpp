#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 300010
#define P 500
int a[N],n,m,cx[N],cy[N];ll f[N+P+10],s[N];
vector<int> d[P+10];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",cx+i,cy+i);
        if(cy[i]<=P)d[cy[i]].push_back(i);else
        {
            ll S=0;
            for(int x=cx[i];x<=n;x+=cy[i])S+=a[x];
            s[i]=S;
        }
    }
    for(int i=1;i<=P;i++)if(!d[i].empty())
    {
        for(int j=n;j>=1;j--)f[j]=f[j+i]+a[j];
        for(int j=0;j<(int)d[i].size();j++)s[d[i][j]]=f[cx[d[i][j]]];
    }
    for(int i=1;i<=m;i++)printf("%I64d\n",s[i]);
    return 0;
}