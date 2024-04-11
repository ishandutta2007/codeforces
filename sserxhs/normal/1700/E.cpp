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
vector<vector<int>> a;
int n,m;
int dx[5]={0,1,0,-1},dy[5]={1,0,-1,0};
bool av(const int &x,const int &y)
{
	return x>=0&&y>=0&&x<n&&y<m;
}
int cal(int x,int y)
{
	for (int j=0;j<4;j++) if (int nx=x+dx[j],ny=y+dy[j];av(nx,ny)&&a[nx][ny]<a[x][y]) return 0;
	return 1;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	cin>>n>>m;
	a.assign(n,vector(m,0));
	int q=n*m;
	vector<pair<int,int>> p(q);
	unordered_set<int> s,tmp;
	int i,j,k,k1,k2;
	for (i=0;i<n;i++) for (j=0;j<m;j++) cin>>a[i][j],p[--a[i][j]]={i,j};
	for (i=1;i<q;i++) if (cal(p[i].first,p[i].second)) s.insert(i);
	if (!s.size())
	{
		cout<<0<<endl;
		return 0;
	}
	int r=0;
	set<pair<int,int>> ans;
	if (s.size()<=10)
	{
		tmp=s;
		int u=*s.begin();
		auto [x,y]=p[u];
		for (i=0;i<n;i++) for (j=0;j<m;j++) for (k=0;k<5;k++) if (int nx=x+dx[k],ny=y+dy[k];av(nx,ny))
		{
			swap(a[i][j],a[nx][ny]);
			for (k1=0;k1<5;k1++) if (int xx=i+dx[k1],yy=j+dy[k1];av(xx,yy)&&a[xx][yy])
			{
				if (cal(xx,yy)) s.insert(a[xx][yy]); else s.erase(a[xx][yy]);
			}
			for (k1=0;k1<5;k1++) if (int xx=nx+dx[k1],yy=ny+dy[k1];av(xx,yy)&&a[xx][yy])
			{
				if (cal(xx,yy)) s.insert(a[xx][yy]); else s.erase(a[xx][yy]);
			}
			if (!s.size())
			{
				if (abs(i-x)+abs(j-y)<=1)
				{
					int u=i*m+j,v=nx*m+ny;
					if (u>v) swap(u,v);
					ans.insert({u,v});
				}
				else ++r;
			}
			s=tmp;
			swap(a[i][j],a[nx][ny]);
		}
	}
	if (r+=ans.size()) cout<<"1 "<<r<<endl; else cout<<2<<endl;
}