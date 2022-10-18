//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream & operator>>(istream &cin,pair<typC,typD> &a) {return cin>>a.first>>a.second;}
template<typename typC> istream & operator>>(istream &cin,vector<typC> &a)
{
	for (auto &x:a) cin>>x;
	return cin;
}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const pair<typC,typD> &a) {return cout<<a.first<<' '<<a.second;}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const vector<pair<typC,typD>> &a)
{
	for (auto &x:a) cout<<x<<'\n';
	return cout;
}
template<typename typC> ostream & operator<<(ostream &cout,const vector<typC> &a)
{
	int n=a.size(),i;
	if (!n) return cout;
	cout<<a[0];
	for (i=1;i<n;i++) cout<<' '<<a[i];
	return cout;
}
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e2+5;
struct union_set
{
	vector<int> f;
	int n;
	union_set(){}
	union_set(int nn):n(nn),f(nn+1)
	{
		iota(all(f),0);
	}
	int getf(int u) {return f[u]==u?u:f[u]=getf(f[u]);}
	void uni(int u,int v)
	{
		u=getf(u);v=getf(v);
		f[u]=v;
	}
	bool con(int u,int v) {return getf(u)==getf(v);}
};
vector<int> e[N];
const int inf=1e9;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j,k;
		cin>>n;
		if (n==2)
		{
			string s;
			cin>>s;
			if (s=="00") cout<<"Yes\n1 2\n"; else cout<<"No\n";
			continue;
		}
		vector<int> ed(n+1);
		vector f(n+1,vector(n+1,bitset<101>(0)));
		vector flg(n+1,vector(n+1,0));
		auto center=flg;
		vector<vector<int>> cs;
		int cnt=n;
		union_set s(n);
		vector dis(n+1,vector(n+1,inf));
		vector<int> cc(n+1);
		vector adj(n+1,vector(n+1,0));
		vector<pair<int,int>> ans;
		for (i=1;i<n;i++)
		{
			for (j=1;j<=n-i;j++)
			{
				string s;
				cin>>s;
				for (k=0;k<n;k++) if (s[k]=='0') f[i][i+j][k+1]=0;
				else f[i][i+j][k+1]=1;
			}
		}
		for (i=1;i<=n;i++) for (j=1;j<i;j++) for (k=1;k<=n;k++) f[i][j][k]=f[j][i][k];
		for (i=1;i<=n;i++) for (j=1;j<=n;j++) flg[i][j]=f[i][j].count();
		for (i=1;i<=n;i++) for (j=i+1;j<=n;j++) if (flg[i][j])
		{
			bitset<101> sta=f[i][j];
			if (flg[i][j]==1)
			{
				center[i][j]=f[i][j]._Find_first();
				continue;
			}
			for (k=1;k<=n;k++) if (f[i][j][k]&&f[i][k][j]) sta&=f[i][k];
			if (sta.count()!=1) continue;
			center[i][j]=sta._Find_first();
		}
		for (i=1;i<=n;i++) for (j=1;j<i;j++) center[i][j]=center[j][i];
	//	for (i=1;i<=n;i++) for (j=i+1;j<=n;j++) if (center[i][j]) dbg(i,j,center[i][j]);
		vector<int> pur;
		vector<int> now(n+1);
		while (cnt)
		{
			//vector<int> buc;
			vector<int> flg(n+1);
			for (i=1;i<=n;i++) if (!ed[i]) for (j=i+1;j<=n;j++) if (!ed[j]) flg[center[i][j]]=1;
			for (i=1;i<=n;i++) if (!ed[i]&&!flg[i])
			{
				pur.push_back(i);
				--cnt;ed[i]=1;
				break;
				//buc.push_back(i);
				//--cnt;
				//ed[i]=1;
			}
			if (i>n) goto no;
			//dbg(buc);
			//if (!buc.size()) goto no;
			//cs.push_back(buc);
		}
		//dbg(pur);
		ans.push_back({pur[n-1],pur[n-2]});
		adj[pur[n-1]][pur[n-2]]=adj[pur[n-2]][pur[n-1]]=1;
		now[pur[n-1]]=now[pur[n-2]]=1;
		for (i=n-3;i>=0;i--)
		{
			int u=pur[i];
			for (j=1;j<=n;j++) if (now[j])
			{
				for (k=1;k<=n;k++) if (now[k]&&k!=j&&adj[j][k]&&center[u][k]==j) break;
				if (k<=n)
				{
					//dbg(u,j);
					ans.push_back({u,j});
					adj[u][j]=adj[j][u]=1;
					break;
				}
			}
			if (j>n) goto no;
			now[u]=1;
		}
		//if (cs.size()==2)
		//{
		//	//dbg(1);
		//	if (cs[1].size()>2) goto no;
		//	if (cs[1].size()==1)
		//	{
		//		for (int x:cs[0]) ans.push_back({cs[1][0],x});
		//	}
		//	else
		//	{
		//		ans.push_back({cs[1][0],cs[1][1]});
		//		for (int x:cs[0])
		//		{
		//			for (j=0;j<2;j++) if (center[x][cs[1][j]]==cs[1][j^1]) break;
		//			if (j==2) goto no;
		//			ans.push_back({cs[1][j^1],x});
		//		}	
		//	}
		//}
		//else
		//{
		//	for (i=0;i<cs.size();i++) for (int x:cs[i]) cc[x]=i;
		//	for (i=1;i<=n;i++) for (j=1;j<=n;j++) if (i!=j&&cc[center[i][j]]==cc[j]+1)
		//	{
		//		dbg(i,j,center[i][j]);
		//		ans.push_back({i,center[i][j]});
		//		ans.push_back({j,center[i][j]});
		//	}
		//	//for (i=0;i+2<cs.size();i++)
		//	//{
		//	//	for (int x:cs[i]) for (int y:cs[i+2]) if (cc[center[x][y]]==i+1)
		//	//	{
		//	//		ans.push_back({x,center[x][y]});
		//	//		ans.push_back({y,center[x][y]});
		//	//	}
		//	//}
		//	//for (i=0;i+1<cs.size();i++) for (int x:cs[i]) for (int y:cs[i]) if (x!=y&&cc[center[x][y]]==i+1)
		//	//{
		//	//	ans.push_back({x,center[x][y]});
		//	//	ans.push_back({y,center[x][y]});
		//	//}
		//}
		for (auto &[x,y]:ans) if (x>y) swap(x,y);
		sort(all(ans));ans.resize(unique(all(ans))-ans.begin());
		//for (auto [x,y]:ans) dbg(x,y);
		if (ans.size()!=n-1) goto no;
		for (auto [x,y]:ans)
		{
			if (x<1||y<1||s.con(x,y)) goto no;
			s.uni(x,y);
			dis[x][y]=1;dis[y][x]=1;
		}
		for (i=1;i<=n;i++) dis[i][i]=0;
		for (k=1;k<=n;k++) for (i=1;i<=n;i++) for (j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		for (i=1;i<=n;i++) for (j=i+1;j<=n;j++) for (k=1;k<=n;k++) if (dis[i][k]==dis[j][k]^f[i][j][k])
		{
			goto no;
		}
		cout<<"Yes\n";
		for (auto [x,y]:ans) cout<<x<<' '<<y<<'\n';
		continue;
		no:cout<<"No\n";//throw;
	}
}