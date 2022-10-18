//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream & operator>>(istream &cin,pair<typC,typD> &a) {return cin>>a.first>>a.second;}
template<typename typC> istream & operator>>(istream &cin,vector<typC> &a){for (auto &x:a) cin>>x;return cin;}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const pair<typC,typD> &a) {return cout<<a.first<<' '<<a.second;}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const vector<pair<typC,typD>> &a){for (auto &x:a) cout<<x<<'\n';return cout;}
template<typename typC> ostream & operator<<(ostream &cout,const vector<typC> &a){int n=a.size();if (!n) return cout;cout<<a[0];for (int i=1;i<n;i++) cout<<' '<<a[i];return cout;}
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e6+5;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		int x,y,z;
		int dis[3][3]={};
		cin>>n>>dis[0][1]>>dis[1][2]>>dis[0][2];
		for (i=0;i<3;i++) for (j=0;j<i;j++) dis[i][j]=dis[j][i];
		int id[3]={0,1,2};
		do
		{
			if (dis[id[2]][id[0]]>=dis[id[0]][id[1]]&&dis[id[2]][id[0]]>=dis[id[1]][id[2]])
				break;
		}
		while (next_permutation(id,id+3));
		if (dis[id[0]][id[2]]>dis[id[0]][id[1]]+dis[id[1]][id[2]]||(1&dis[id[0]][id[2]]+dis[id[0]][id[1]]+dis[id[1]][id[2]]))
		{
			cout<<"NO\n";
			continue;
		}
		int tot=dis[id[0]][id[2]]+dis[id[0]][id[1]]+dis[id[1]][id[2]]>>1;
		int d[3];
		for (i=0;i<3;i++)
		{
			set<int> s{0,1,2};
			s.erase(i);
			d[i]=tot-dis[*s.begin()][*s.rbegin()];
		}
		if (d[0]+d[1]+d[2]+1>n)
		{
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		vector<pair<int,int>> edges;
		if (d[id[1]]==0)
		{
			int now=3;
			{
				vector<int> a(d[id[0]]-1);
				iota(all(a),now);
				now=a.size()?a.back()+1:now;
				a.insert(a.begin(),id[0]);
				a.push_back(id[1]);
				for (i=1;i<a.size();i++) edges.push_back({a[i-1],a[i]});
			}
			swap(id[0],id[2]);
			{
				vector<int> a(d[id[0]]-1);
				iota(all(a),now);
				now=a.size()?a.back()+1:now;
				a.insert(a.begin(),id[0]);
				a.push_back(id[1]);
				for (i=1;i<a.size();i++) edges.push_back({a[i-1],a[i]});
			}
			for (i=now;i<n;i++) edges.push_back({i-1,i});
		}
		else
		{
			int now=4;
			for (int x:id)
			{
				vector<int> a(d[x]-1);
				iota(all(a),now);
				now=a.size()?a.back()+1:now;
				a.insert(a.begin(),x);
				a.push_back(3);
				for (i=1;i<a.size();i++) edges.push_back({a[i-1],a[i]});
			}
			for (i=now;i<n;i++) edges.push_back({i-1,i});
		}
		for (auto &[u,v]:edges) ++u,++v;
		cout<<edges;
	}
}