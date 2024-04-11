#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k;
int x[MAXN],y[MAXN];
int d[MAXN];
int get_dist(int i,int j)
{
    return max(x[i]-x[j],x[j]-x[i])+max(y[i]-y[j],y[j]-y[i]);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
        bool f=false;
        for(int i=1;i<=n;i++)
        {
            bool flag=true;
            for(int j=1;j<=n;j++) if(get_dist(i,j)>k) flag=false;
            if(flag) f=true;
        }
        if(f) puts("1"); else puts("-1");
    }
    return 0;
}