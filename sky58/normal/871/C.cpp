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
#include<cassert>
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
vector<int> sx,sy;
map<int,int> dx,dy;
int x[114514],y[114514];
vector<int> gr[252521];
bool used[252521];
lint zyo[252521];
lint mo=1000000007;
int nv,ne;
void dfs(int v,int u){
	if(used[v]) return;
	nv++;used[v]=true;
	rep(i,gr[v].size()){
		int w=gr[v][i];
		if(w==u) continue;
		ne++;dfs(w,v);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	rep(i,n){
		scanf("%d %d",&x[i],&y[i]);
		sx.pb(x[i]);sy.pb(y[i]);
	}
	sort(All(sx));sx.erase(unique(All(sx)),sx.end());
	sort(All(sy));sy.erase(unique(All(sy)),sy.end());
	rep(i,sx.size()) dx[sx[i]]=i;
	rep(i,sy.size()) dy[sy[i]]=i;
	int m=sx.size()+sy.size();
	rep(i,n){
		int a=dx[x[i]],b=sx.size()+dy[y[i]];
		gr[a].pb(b);gr[b].pb(a);
	}
	zyo[0]=1;rep(i,252500) zyo[i+1]=(zyo[i]*2)%mo;
	memset(used,false,sizeof(used));
	lint out=1;
	rep(i,m){
		if(used[i]) continue;
		nv=0;ne=0;dfs(i,-1);
		if(ne>=nv) out*=zyo[nv];
		else out*=zyo[nv]-1;
		out%=mo;
	}
	cout<<out%mo<<endl;
}