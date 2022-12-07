#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define crp make_pair
using namespace std;
typedef long long ll;
const int Mod=1e9+7;
int add(int a,const int b){a+=b;if(a>=Mod)a-=Mod;return a;}
int mul(const int a,const int b){return (ll)a*b%Mod;}
const int N=4e6+50;
int n,m,tot,cnt,now,num=0;
int h[10],g[10],det[N],f[N],dp[N][2],stk[2][N],top[2];
vector<pii> e[N];
void build(int u,int v,int w)
{
	int x,i;
	cnt=0;
	x=w;
	while(x>0) h[++cnt]=x%10,x/=10;
	reverse(h+1,h+cnt+1);
	for(i=1;i<cnt;i++) g[i]=++tot;
	g[0]=u;
	g[cnt]=v;
	for(i=1;i<=cnt;i++) e[g[i-1]].pb(crp(h[i],g[i]));
}
bool cmp(const int &a,const int &b)
{
	if(dp[a][0]!=dp[b][0]) return dp[a][0]<dp[b][0];
	else return dp[a][1]<dp[b][1]; 
}
int main()
{
	int x,i,u,v,w,c=0;
	scanf("%d%d",&n,&m);
	tot=n;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		build(u,v,i);build(v,u,i);
	}
	top[1]=1;det[1]=1;stk[1][1]=1;now=1;
	for(i=1;i<=tot;i++) sort(e[i].begin(),e[i].end());
	while(now>0)
	{
		c^=1;
		sort(stk[c]+1,stk[c]+top[c]+1,cmp);
		top[c^1]=0;
		num=0;now=0;
		for(i=1;i<=top[c];i++)
		{
			if(i==1||(dp[stk[c][i]][0]!=dp[stk[c][i-1]][0]||dp[stk[c][i]][1]!=dp[stk[c][i-1]][1])) num++;
			x=stk[c][i];
			for(pii bno:e[x])
			{
				v=bno.second;w=bno.first;
				if(det[v]==0||(det[v]==det[x]+1&&dp[v][0]==num&&w<dp[v][1]))
				{
					now++;
					dp[v][0]=num;dp[v][1]=w;
					f[v]=add(mul(f[x],10),w);
					if(!det[v])
					{
						det[v]=det[x]+1;
						stk[c^1][++top[c^1]]=v;
					}
				}
			}
		}
	}
	for(i=2;i<=n;i++) printf("%d\n",f[i]);
	return 0;
}