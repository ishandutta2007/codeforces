#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,r,c,L,R,ans=0;
char mp[2005][2005];
bool vis[2005][2005];
struct node
{
    int x,y,l,r;
};
deque<node> q;
inline void go(int x,int y,int l,int r,int t)
{
	if(mp[x][y]=='.'&&!vis[x][y]&&l<=L&&r<=R)
	{
		vis[x][y]=true;
		if(t) q.push_front((node){x,y,l,r});
		else q.push_back((node){x,y,l,r});
	}
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%d%d",&r,&c);
    scanf("%d%d",&L,&R);
    for(int i=1;i<=n;i++) scanf("%s",mp[i]+1); 
    memset(vis,false,sizeof(vis));
    q.push_front((node){r,c,0,0});vis[r][c]=true;
    while(q.size())
    {
        node qq=q.front();q.pop_front();ans++;
        if(qq.x>1) go(qq.x-1,qq.y,qq.l,qq.r,1);
        if(qq.x<n) go(qq.x+1,qq.y,qq.l,qq.r,1);
        if(qq.y>1) go(qq.x,qq.y-1,qq.l+1,qq.r,0);
        if(qq.y<m) go(qq.x,qq.y+1,qq.l,qq.r+1,0);
    }
    printf("%d\n",ans);
    return 0;
}