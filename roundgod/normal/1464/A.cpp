#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
int perm[MAXN];
bool vis[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) perm[i]=0;
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(x!=y) {perm[x]=y; cnt++;} 
        }
        for(int i=1;i<=n;i++) vis[i]=false;
        for(int i=1;i<=n;i++)
        {
            if(perm[i]&&!vis[i])
            {
                int now=i;
                while(!vis[now]&&perm[now])
                {
                    vis[now]=true;
                    now=perm[now];
                }
                if(now==i) cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}