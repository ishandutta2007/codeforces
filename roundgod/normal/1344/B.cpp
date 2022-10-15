#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
char mp[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
void bfs(int x,int y)
{
    queue<P> que;
    que.push(P(x,y));
    while(que.size())
    {
        P p=que.front(); que.pop();
        if(vis[p.F][p.S]) continue;
        vis[p.F][p.S]=true;
        for(int k=0;k<4;k++)
        {
            int nx=p.F+dx[k],ny=p.S+dy[k];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&!vis[nx][ny]&&mp[nx][ny]=='#') que.push(P(nx,ny));
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%s",mp[i]);
    int erow=0,ecol=0;
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        for(int j=0;j<m;j++) cnt+=(mp[i][j]=='#');
        if(cnt==0) erow++;
    }
    for(int i=0;i<m;i++)
    {
        int cnt=0;
        for(int j=0;j<n;j++) cnt+=(mp[j][i]=='#');
        if(cnt==0) ecol++;
    }
    if((!ecol&&erow)||(!erow&&ecol)) {puts("-1"); return 0;}
    bool f=true;
    for(int i=0;i<n;i++)
    {
        int last=-1;
        for(int j=0;j<m;j++)
            if(mp[i][j]=='#')
            {
                if(last!=-1&&last!=j-1) f=false;
                last=j;
            }
    }
    for(int i=0;i<m;i++)
    {
        int last=-1;
        for(int j=0;j<n;j++)
            if(mp[j][i]=='#')
            {
                if(last!=-1&&last!=j-1) f=false;
                last=j;
            }
    }
    if(!f) {puts("-1"); return 0;}
    int cnt=0;
    memset(vis,false,sizeof(vis));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(mp[i][j]=='#'&&!vis[i][j])
            {
                bfs(i,j);
                cnt++;
            }
        }
    printf("%d\n",cnt);
    return 0;
}