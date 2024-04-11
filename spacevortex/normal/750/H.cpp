#include<bits/stdc++.h>
#define pii pair<ll,ll>
#define crp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const ll P=1050,N=P*P,W=1e9;
ll n,m,Q,num=0,top,S,T;
map<ll,bool> mp;
void ins(ll u,ll v){if(u==v) return ;if(u>v) swap(u,v);mp[u*W+v]=1;}
bool chk(ll u,ll v){if(u>v) swap(u,v);return mp[u*W+v];}
char s[P];
ll t[P][P],col[P][P],p[20];
ll cx[8]={1,-1,0,0,1,1,-1,-1},cy[8]={0,0,1,-1,-1,1,-1,1};
void dfs(ll x,ll y)
{
	ll i,nx,ny;
	col[x][y]=num;
	//printf("col %lld %lld  : %lld\n",x,y,num);
	for(i=0;i<8;i++)
	{
		nx=x+cx[i];ny=y+cy[i];
		if(t[nx][ny]&&(!col[nx][ny])) dfs(nx,ny);
	}
}
void init()
{
	ll i,j,k,k1,k2,nx,ny;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(t[i][j]&&(!col[i][j])) 
			{
				num++;
				dfs(i,j); 
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if((i==2&&j==2)||(i==n-1&&j==m-1)) continue;
			if(t[i][j]==0)
			{
				top=0;
				for(k=0;k<8;k++)
				{
					nx=i+cx[k];ny=j+cy[k];
					if(col[nx][ny]) p[++top]=col[nx][ny]; 
				}
				sort(p+1,p+top+1);
				top=unique(p+1,p+top+1)-p-1;
				for(k1=1;k1<top;k1++)
				for(k2=k1+1;k2<=top;k2++)
				{
					ins(p[k1],p[k2]);
				}
			}
		}
	}
}
ll K,tim=0;
vector<ll> e[N];
ll px[20],py[20];
void eadd(ll u,ll v){e[u].pb(v);e[v].pb(u);}
ll vis[N];
vector<ll> vec[2];
void srh(ll x,ll c)
{ 
	vis[x]=tim;
	vec[c].pb(x);
	for(ll v:e[x])
	{
		if(vis[v]==tim) continue;
		srh(v,c);
	}
}
bool mchk(ll i1,ll i2)
{
	//printf("mchk %lld %lld\n",i1,i2);
	if(i1<i2) swap(i1,i2);
	if(i1>num&&i2>num) 
	{
		i1-=num;i2-=num;
		//printf("A %lld %lld   B %lld %lld\n",px[i1],py[i1],px[i2],py[i2]);
		return max(abs(px[i1]-px[i2]),abs(py[i1]-py[i2]))<=2;
	}
	if(i1>num)
	{
		ll x,y,nx,ny;
		x=px[i1-num];y=py[i1-num];
		//printf("R %lld   %lld %lld\n",i1,x,y);
		for(nx=x-2;nx<=x+2;nx++)
		{
			for(ny=y-2;ny<=y+2;ny++)
			{
				if(nx>=1&&nx<=n&&ny>=1&&ny<=m)
				{
					//printf("P %lld %lld  %lld %lld\n",nx,ny,col[nx][ny],i2);
					if(col[nx][ny]==i2) return 1;
				}
			}
		}
		return 0;
	}
	else
	{
		return chk(i1,i2);
	}
}
bool solve()
{
	ll i,j,x,y,nx,ny;
	scanf("%lld",&K);
	for(i=1;i<=K;i++)
	{
		scanf("%lld%lld",&x,&y);
		x++;y++;
		px[i]=x;py[i]=y;
		col[x][y]=num+i;
	}
	for(i=1;i<=K;i++)
	{
		x=px[i];y=py[i];
		for(j=0;j<8;j++)
		{
			nx=x+cx[j];ny=y+cy[j];
			/*
			if(i==3)
			{
				printf("U %lld %lld  %lld %lld  %lld\n",x,y,nx,ny,col[nx][ny]);
			}
			*/
			if(col[nx][ny]) eadd(num+i,col[nx][ny]);
		}
	}
	S=col[3][1];T=col[1][3];
	//printf("S %lld   T %lld\n",S,T);
	vec[0].clear();vec[1].clear();
	tim++;
	srh(S,0);
	srh(T,1);
	for(i=1;i<=K;i++)
	{
		x=px[i];y=py[i];
		col[x][y]=0;e[num+i].clear();
		for(j=0;j<8;j++)
		{
			nx=x+cx[j];ny=y+cy[j];
			if(col[nx][ny]) e[col[nx][ny]].clear();
		}
	}

	for(ll x:vec[0]) if(x==T) return 1;

	for(ll x:vec[0])
	{
		for(ll y:vec[1])
		{
			if(mchk(x,y)) return 1;
		}
	}
	
	return 0;
}
int main()
{
	ll i,j;
	scanf("%lld%lld%lld",&n,&m,&Q);
	n+=2;m+=2;
	for(i=2;i<n;i++)
	{
		scanf("%s",s+1);
		for(j=2;j<=m;j++) if(s[j-1]=='#') t[i][j]=1;
	}
	for(i=3;i<=m;i++) t[1][i]=1;
	for(i=2;i<=n-2;i++) t[i][m]=1;
	
	for(i=3;i<=n;i++) t[i][1]=1;
	for(i=2;i<=m-2;i++) t[n][i]=1;
	init();
	while(Q--)
	{
		if(solve()) puts("NO");
		else puts("YES");
		fflush(stdout);
	}
	return 0;
}