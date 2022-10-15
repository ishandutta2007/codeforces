#include<bits/stdc++.h>
#define MAXN 305
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
P p[MAXN];
int seat[MAXN];
bool vis[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++) 
        {
            scanf("%d",&p[i].F);
            p[i].S=-i;
        }
        sort(p+1,p+m+1);
        int ans=0;
        for(int i=1;i<=m;i++) vis[i]=false;
        for(int i=1;i<=m;i++) seat[-p[i].S]=i;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<seat[i];j++)
                if(vis[j]) ans++;
            vis[seat[i]]=true;
        }
        printf("%d\n",ans);
    }
    return 0;
}