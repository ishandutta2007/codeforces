#include<bits/stdc++.h>
#define MAXN 305
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,a[MAXN][MAXN];
vector<int> dis;
vector<int> save[MAXN*MAXN];
int pos[MAXN*MAXN];
bool vis[MAXN][MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        dis.clear();
        for(int i=0;i<n*m;i++) save[i].clear();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                scanf("%d",&a[i][j]);
                dis.push_back(a[i][j]);
            }
        sort(dis.begin(),dis.end());
        dis.erase(unique(dis.begin(),dis.end()),dis.end());
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                int pos=lower_bound(dis.begin(),dis.end(),a[i][j])-dis.begin();
                save[pos].push_back(i*m+j);
            }
        int sz=(int)dis.size();
        int now=0;
        for(int i=0;i<sz;i++)
        {
            sort(save[i].begin(),save[i].end(),greater<int>());
            while(save[i].size())
            {
                int rem=m-now%m;
                int need=min((int)save[i].size(),rem);
                int l=now,r=now+need-1;
                now+=need;
                for(int j=0;j<need;j++)
                {
                    pos[save[i].back()]=r;
                    save[i].pop_back();
                    r--;
                }
            }
        }
        for(int i=0;i<n;i++) 
            for(int j=0;j<m;j++)
                vis[i][j]=false;
        int ans=0;
        for(int i=0;i<n*m;i++)
        {
            int x=pos[i]/m,y=pos[i]%m;
            for(int j=0;j<y;j++) if(vis[x][j]) ans++;
            vis[x][y]=true;
        }
        printf("%d\n",ans);
    }
    return 0;
}