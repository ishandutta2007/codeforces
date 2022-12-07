#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Point{ll x,y;};
Point operator -(Point a,Point b){return (Point){a.x-b.x,a.y-b.y};}
ll operator *(Point a,Point b){return a.x*b.x+a.y*b.y;}
ll cross(Point a,Point b){return a.x*b.y-a.y*b.x;}
const ll N=1050;
ll n,K,top,ans=0,tim;
Point A[N];
ll p[10][N][N],stk[N],ins[N],tg[N];
bool vis[10];
bool dfs(ll xh)
{
	if(top==0) return 1;
	ll i,j,k,now,las,pd;
	now=stk[top];
	for(i=1;i<=K;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		las=top;
		top--;
		for(j=1;j<=p[i][now][0];j++) 
		{
			if(tg[p[i][now][j]]!=tim)
			{
				stk[++top]=p[i][now][j];
				tg[stk[top]]=tim;
			}
		}
		if(top<xh&&dfs(xh-1)==1) return 1;
		while(top>=las) tg[stk[top--]]=0;
		stk[++top]=now;
		vis[i]=0;
	}
	return 0;
}
int main()
{
	ll i,j,k;
	cin>>K>>n;
	for(i=1;i<=K;i++) cin>>A[n+i].x>>A[n+i].y;
	for(i=1;i<=n;i++) cin>>A[i].x>>A[i].y;
	for(i=1;i<=K;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				if(cross(A[k]-A[n+i],A[j]-A[n+i])==0&&(A[k]-A[n+i])*(A[k]-A[j])<0)
				{
					p[i][j][++p[i][j][0]]=k;
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		tim++;tg[i]=tim;
		top=1;stk[1]=i;
		memset(vis,0,sizeof(vis));
		if(dfs(K)==1) ans++;
	}
	cout<<ans;
	return 0;
}