#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define MAXS 605
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,a[MAXN],tot;
int threshold;
vector<int> save[MAXS];
vector<int> big;
vector<int> dis;
int cnt[MAXN];
vector<int> bad[MAXN];
map<int,int> id;
string str;
int get_id(int v)
{
	return lower_bound(dis.begin(),dis.end(),v)-dis.begin()+1;
}
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
	int s=1;
	while(i)
	{
		if(i&1) s=1LL*s*a%MOD;
		a=1LL*a*a%MOD;
		i>>=1;
	}
	return s;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		tot=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) bad[i].clear();
		for(int i=1;i<=n;i++) cnt[i]=0;
		big.clear(); dis.clear();
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&a[i]); dis.push_back(a[i]);
		}
		sort(dis.begin(),dis.end());
		dis.erase(unique(dis.begin(),dis.end()),dis.end());
		for(int i=1;i<=n;i++) cnt[get_id(a[i])]++;
		for(int i=0;i<m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			u=get_id(u); v=get_id(v);
			bad[u].push_back(v); bad[v].push_back(u);
		}
		for(int i=1;i<=(int)dis.size();i++) sort(bad[i].begin(),bad[i].end());
		threshold=(int)sqrt(n);
		for(int i=1;i<=threshold;i++) save[i].clear(); 
		for(int i=1;i<=(int)dis.size();i++)
		{
			if(cnt[i]<=threshold) save[cnt[i]].push_back(i); else big.push_back(i);
		}
		vector<int> tmp[MAXS];
		ll ans=0;
		for(int o=1;o<=(int)dis.size();o++)
		{
			for(int i=1;i<=threshold+1;i++) tmp[i].clear();
			for(auto to:bad[o]) if(cnt[to]<=threshold) tmp[cnt[to]].push_back(to); else tmp[threshold+1].push_back(to);
			for(int i=1;i<=threshold;i++)
			{
				int x=(int)save[i].size()-1,y=(int)tmp[i].size()-1;
				if(x>=0&&save[i][x]==o) x--;
				while(x>=0&&y>=0&&save[i][x]==tmp[i][y]) {x--; y--; if(x>=0&&save[i][x]==o) x--;}
				if(x>=0) ans=max(ans,1LL*(dis[o-1]+dis[save[i][x]-1])*(cnt[o]+i));
			}
			int x=(int)big.size()-1,y=(int)tmp[threshold+1].size()-1;
			if(x>=0&&big[x]==o) x--;
			while(x>=0&&y>=0&&big[x]==tmp[threshold+1][y]) {x--; y--; if(x>=0&&big[x]==o) x--;}
			if(x>=0) ans=max(ans,1LL*(dis[o-1]+dis[big[x]-1])*(cnt[o]+cnt[big[x]]));
		}
		printf("%lld\n",ans);
	}
	return 0;
}