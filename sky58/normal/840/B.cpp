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
struct unionf{
	vector <int> data;
	unionf(int size):data(size,-1){}
	bool unions(int x,int y){
		x=root(x);y=root(y);
		if(x!=y){
			if(data[y]<data[x]){int d=x;x=y;y=d;}
			data[x]+=data[y];data[y]=x;
		}
		return x!=y;
	}
	bool finds(int x,int y){
		return root(x)==root(y);
	}
	int root(int x){
		return data[x]<0?x:data[x]=root(data[x]);
	}
	int find(int x){
		return -data[x];
	}
};
int d[364364];
vector<pint> gr[364364];
int dp[364364];
bool used[364364];
int dfs(int v,int u){
	bool mi=false;int num=0,ret;
	rep(i,gr[v].size()){
		pint p=gr[v][i];
		if(p.fi==u) continue;
		int x=dfs(p.fi,v);
		if(x<0) mi=true;else num+=x;
	}
	num%=2;
	if(mi) ret=-1;else ret=(num+d[v])%2;
	return dp[v]=ret;
}
void dfs2(int v,int u,int pa){
	//cout<<v<<' '<<u<<' '<<pa<<endl;
	bool mi=false;int num=0,ret;
	rep(i,gr[v].size()){
		pint p=gr[v][i];
		if(p.fi==u) continue;
		int x=dp[p.fi];
		if(x>=0) num+=x;
	}
	num%=2;//cout<<num<<endl;
	rep(i,gr[v].size()){
		pint p=gr[v][i];
		if(p.fi==u) continue;
		int x=dp[p.fi];
		//if(v==0) cout<<x<<endl;
		if(x<0 && num!=pa){
			if(!mi){
				//cout<<p.fi<<endl;
				dfs2(p.fi,v,(d[p.fi]+1)%2);
				used[p.se]=true;
				mi=true;
			}
			else{
				dfs2(p.fi,v,d[p.fi]);
			}
		}
		else{
			if(x>0){
				dfs2(p.fi,v,(d[p.fi]+1)%2);
				used[p.se]=true;
			}
			else{
				dfs2(p.fi,v,d[p.fi]);
			}
		}
	}
}
int main()
{
	int n,m,a,b;
	scanf("%d %d",&n,&m);
	unionf uni(n+10);
	rep(i,n) scanf("%d",&d[i]);
	rep(i,m){
		scanf("%d %d",&a,&b);
		a--;b--;
		if(uni.finds(a,b)) continue;
		uni.unions(a,b);
		gr[a].pb(mp(b,i));gr[b].pb(mp(a,i));
	}
	dfs(0,-1);
	//rep(i,n) cout<<i<<' '<<dp[i]<<endl;
	if(dp[0]>0){
		cout<<-1<<endl;return 0;
	}
	dfs2(0,-1,d[0]);
	vector<int> ret;
	rep(i,m){
		if(used[i]) ret.pb(i+1);
	}
	a=ret.size();
	printf("%d\n",a);
	rep(i,a){
		printf("%d\n",ret[i]);
	}
}