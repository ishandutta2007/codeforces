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
int dp[5010][5010][2];
int inf=1001001001;
vector<int> gr[5010];
int a[5010][2];
int ch[5010];
int dfs(int v){
	ch[v]=1;
	rep(i,gr[v].size()) ch[v]+=dfs(gr[v][i]);
	return ch[v];
}
int dfs2(int v){
	
	//not use
	vector<int> now(1,0);now.pb(a[v][0]);
	rep(i,gr[v].size()){
		int w=gr[v][i];
		dfs2(w);
		vector<int> ne(now.size()+ch[w],inf);
		rep(j,now.size()) rep(k,ch[w]+1) ne[j+k]=min(ne[j+k],now[j]+dp[w][k][0]);
		now=ne;
	}
	assert(ch[v]+1==now.size());
	rep(i,now.size()) dp[v][i][0]=now[i];
	
	//use
	now.clear();now.pb(inf);now.pb(a[v][1]);
	rep(i,gr[v].size()){
		int w=gr[v][i];
		vector<int> ne(now.size()+ch[w],inf);
		rep(j,now.size()) rep(k,ch[w]+1) ne[j+k]=min(ne[j+k],now[j]+dp[w][k][1]);
		now=ne;
	}
	assert(ch[v]+1==now.size());
	rep(i,now.size()) dp[v][i][1]=min(dp[v][i][0],now[i]);
}
int main()
{
	int n,b,x,out=0;
	cin>>n>>b;
	rep(i,n){
		cin>>a[i][0]>>a[i][1];
		a[i][1]=a[i][0]-a[i][1];
		if(i>0){
			cin>>x;x--;gr[x].pb(i);
		}
	}
	dfs(0);dfs2(0);
	rep(i,n+1){
		if(dp[0][i][1]<=b) out=max(out,i);
	}
	cout<<out<<endl;
}