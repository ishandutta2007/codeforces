#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x[MAXN],y[MAXN],z[MAXN];
bool used[MAXN];
ll getdis2(int i,int j)
{
    return 1LL*(x[i]-x[j])*(x[i]-x[j])+1LL*(y[i]-y[j])*(y[i]-y[j])+1LL*(z[i]-z[j])*(z[i]-z[j]);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d%d",&x[i],&y[i],&z[i]);
    memset(used,false,sizeof(used));
    for(int i=1;i<=n;i++)
    {
        if(used[i]) continue;
        ll res=INF;
        int id=-1;
        for(int j=i+1;j<=n;j++)
        {
            if(used[j]) continue;
            if(getdis2(i,j)<res)
            {
                res=getdis2(i,j);
                id=j;
            }
        }
        used[i]=used[id]=true;
        printf("%d %d\n",i,id);
    }
    return 0;
}