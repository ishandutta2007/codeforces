#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const int C = 333;
vi adj[222222];
int vis[222222];
int oncyc[222222];
int a[222222];
int posid[222222];
pair<int,ll> queries[111111];
int ans[222222];
int h[222222];
vector<int> dp[222222];
int cycsiz[222222];
int base[222222];
int sub[222222];
int s[222222];
int e[222222];
vi collection[222222];
int timer=0;

void dfs(int u, int p, int r)
{
	sub[r]++;
	base[u]=r;
	s[u]=++timer;
	int ht=h[u];
	collection[ht].pb(s[u]);
	if(ht<dp[r].size())
	{
		dp[r][ht]++;
	}
	else
	{
		assert(ht==dp[r].size());
		dp[r].pb(1);
	}
	for(int v:adj[u])
	{
		if(oncyc[v]>=0) continue;
		if(v==p) continue;
		h[v]=h[u]+1;
		dfs(v,u,r);
	}
	e[u]=++timer;
}

int get(int x, int c, ll m) //sum of all =m mod c and <=m
{
	if(m<0) return 0;
	int siz=dp[x].size();
	if(m<siz) return dp[x][m];
	int rem = m%c;
	//c*k+rem<=siz-1
	//c*k<=siz-1-rem
	//cerr<<"SIZ: "<<x<<' '<<siz<<'\n';
	int rr = siz-1-rem;
	if(rr<0) return 0;
	int k=rr/c;
	//cerr<<"GET: DP "<<x<<' '<<rem<<' '<<c*k<<' '<<rem+c*k<<'\n';
	return dp[x][rem+c*k];
}



int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(oncyc,-1,sizeof(oncyc));
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]; a[i]--;
		adj[a[i]].pb(i);
	}
	vector<vi> cycles;
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			vi cyc;
			int cur=i;
			while(!vis[cur])
			{
				vis[cur]=1; cur=a[cur];
			}
			//cerr<<i<<' '<<cur<<' '<<vis[cur]<<'\n';
			if(vis[cur]==2) 
			{
				cur=i;
				while(vis[cur]<2)
				{
					vis[cur]=2; cur=a[cur];
				}
				continue;
			}
			if(vis[cur]==1)
			{
				while(vis[cur]<2)
				{
					cyc.pb(cur); vis[cur]=2; oncyc[cur]=cycles.size(); cur=a[cur];
				}
				cycsiz[cycles.size()]=cyc.size();
				for(int i=0;i<cyc.size();i++)
				{
					posid[cyc[i]]=i;
				}
				cycles.pb(cyc);
			}
		}
	}
	for(vi &C:cycles)
	{
		int c=C.size();
		for(int x:C)
		{
			h[x]=0;
			dfs(x,-1,x);
			//cerr<<"SIZ: "<<x<<' '<<dp[x].size()<<'\n';
			for(int i=c;i<dp[x].size();i++)
			{
				dp[x][i]+=dp[x][i-c];
			}
		}
	}
	vi big;
	for(int i=0;i<n;i++)
	{
		if(sub[i]>=C)
		{
			big.pb(i);
		}
	}
	int q; cin>>q;
	for(int z=0;z<q;z++)
	{
		ll m; int u; cin>>m>>u; u--;
		int cycid = oncyc[u];
		//cerr<<m<<' '<<u<<' '<<cycid<<'\n';
		if(cycid>=0)
		{
			int c = cycsiz[cycid];
			int r=m%c;
			int posi=posid[u];
			posi-=r;
			posi%=c;
			if(posi<0) posi+=c;
			int cur=cycles[cycid][posi];
			int oricur=cur;
			for(int d=0;d<=C;d++)
			{
				if(d>0&&cur==oricur) break;
				ll steps=m-r+d;
				if(d>r) steps-=c;
				//cerr<<"CUR: "<<cur<<' '<<d<<' '<<steps<<' '<<get(cur,c,steps)<<'\n';
				ans[z]+=get(cur,c,steps);
				cur=a[cur];
			}
			for(int bb:big)
			{
				if(oncyc[bb]==cycid)
				{
					int initid=posi;
					int curid=posid[bb];
					int dist=0;
					bool done=0;
					if(c>C)
					{
						if(initid<=curid)
						{
							dist=curid-initid;
						}
						else
						{
							dist=curid+c-initid;
						}
						if(dist<=C) done=1;
					}
					else done=1;
					if(!done)
					{
						ll steps=m-r+dist;
						if(dist>r) steps-=c;
						ans[z]+=get(bb,c,steps);
					}
				}
			}
		}
		else
		{
			m+=h[u];
			if(m>=211111)
			{
				ans[z]=0; continue;
			}
			int S=s[u]; int E=e[u];
			int lb=lower_bound(collection[m].begin(),collection[m].end(),S)-collection[m].begin();
			int lb2=lower_bound(collection[m].begin(),collection[m].end(),E+1)-collection[m].begin();
			lb2--;
			ans[z]=lb2-lb+1;
		}
	}
	for(int z=0;z<q;z++)
	{
		cout<<ans[z]<<'\n';
	}
}