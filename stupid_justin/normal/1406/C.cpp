#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define R register
#define I inline
 
using namespace std;
 
const int N=1e5+5;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const int mod2=998244353;
 
I int ksm(int x,int y,int z){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}}
 
int n,m,k,ans,cnt,res;
int a[N];
int b[N];
int num[N];
int p[N];
int sz[N];
bool vis[N];
int fa[N];
string str;
map<int,int> Map;
vector<int> vec[N];
 
void add(int u,int v){vec[u].push_back(v);vec[v].push_back(u);}
 
void dfs(int x)
{
	vis[x]=1;
    for(int i=0;i<vec[x].size();i++)
    {
        if(!vis[vec[x][i]])
        {
        	fa[vec[x][i]]=x;
        	dfs(vec[x][i]);
            sz[x]+=sz[vec[x][i]];
        }
    }
    sz[x]++;
}
 
 
 
signed main()
{
	srand(time(NULL));
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n;
		
		for (int i=1;i<n;i++) 
		{
			int u,v;
			cin>>u>>v;
			add(u,v);
		}
		for (int i=1;i<=n;i++) vis[i]=0;
		dfs(1);
		int minn=inf;
		int maxx=-inf;
		for (int i=1;i<=n;i++) 
		{
			int maxn=n-sz[i];
			for (int j=0;j<vec[i].size();j++) 
				if (vec[i][j]==fa[i]) maxn=max(maxn,sz[vec[i][j]]-sz[i]);
				else maxn=max(maxn,sz[vec[i][j]]);
			p[i]=maxn;
		}
		
		
		cnt=0;
		for (int i=1;i<=n;i++) minn=min(minn,p[i]);
		for (int i=1;i<=n;i++) if (p[i]==minn) cnt++;
		if (cnt==1)
		{
			printf("1 %d\n1 %d\n",vec[1][0],vec[1][0]);
		}
		else
		{
			int id[2];
			int CNT=0;
			for (int i=1;i<=n;i++) if (p[i]==minn) id[CNT++]=i;
			for (int i=1;i<=n;i++)
			{
				int can=-1;
				if (i==id[0] || i==id[1]) continue;
				for (int j=0;j<vec[i].size();j++) 
				{
					if (vec[i][j]==id[0]) can=0;
					if (vec[i][j]==id[1]) can=1;
				}
				if (can!=-1)
				{
					printf("%d %d\n",id[can],i);
					printf("%d %d\n",id[1-can],i);
					break;
				}
			}
		}
		for (int i=1;i<=n;i++) vec[i].clear();
		for (int i=1;i<=n;i++) p[i]=0;
		for (int i=1;i<=n;i++) sz[i]=0;
	}
}