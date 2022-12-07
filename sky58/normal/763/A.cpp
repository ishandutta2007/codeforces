#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
vector<int> gr[114514];
vector<pint> ed;
int c[114514];
bool ok;
void dfs(int v,int u,int nc){
	if(nc>=0 && c[v]!=nc){
		ok=false;return;
	}
	nc=c[v];
	rep(i,gr[v].size()){
		int w=gr[v][i];
		if(w==u) continue;
		dfs(w,v,nc);
	}
}
int main()
{
	int n,a,b;
	scanf("%d",&n);
	rep(i,n-1){
		scanf("%d %d",&a,&b);
		a--;b--;ed.pb(mp(a,b));gr[a].pb(b);gr[b].pb(a);
	}
	rep(i,n) scanf("%d",&c[i]);
	a=-1;b=-1;
	rep(i,n-1){
		if(c[ed[i].fi]!=c[ed[i].se]) a=ed[i].fi,b=ed[i].se;
	}
	if(a<0){
		cout<<"YES"<<endl;cout<<1<<endl;return 0;
	}
	ok=true;
	rep(i,gr[a].size()) dfs(gr[a][i],a,-1);
	if(ok){
		cout<<"YES"<<endl;cout<<a+1<<endl;return 0;
	}
	ok=true;
	rep(i,gr[b].size()) dfs(gr[b][i],b,-1);
	if(ok){
		cout<<"YES"<<endl;cout<<b+1<<endl;return 0;
	}
	cout<<"NO"<<endl;
}