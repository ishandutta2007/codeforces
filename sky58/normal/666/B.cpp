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
int len[3010][3010];
vector<pint> fr[3010],to[3010];
vector<int> gr[3010];
int inf=114514;
queue<int> q;
void aedge(int u,int v,int d){
	if(len[u][v]<=d) return;
	len[u][v]=d;q.push(v);
}
int main()
{
	int ma=0,a,b,c,d,n,m;
	cin>>n>>m;
	rep(i,m){
		cin>>a>>b;gr[a].pb(b);
	}
	rep(i,3010) rep(j,3010) len[i][j]=inf;
	REP(i,1,n+1){
		aedge(i,i,0);
		while(!q.empty()){
			int p=q.front();q.pop();
			rep(j,gr[p].size()) aedge(i,gr[p][j],len[i][p]+1);
		}
	}
	REP(i,1,n+1) REP(j,1,n+1){
		if(i==j || len[i][j]>=inf) continue;
		fr[j].pb(mp(len[i][j],i));
		to[i].pb(mp(len[i][j],j));
	}
	REP(i,1,n+1){
		sort(All(fr[i]));reverse(All(fr[i]));
		sort(All(to[i]));reverse(All(to[i]));
	}
	REP(i,1,n+1) REP(j,1,n+1){
		if(i==j || len[i][j]>=inf) continue;
		rep(k,min(5,(int)fr[i].size())) rep(l,min(5,(int)to[j].size())){
			int co=fr[i][k].fi+len[i][j]+to[j][l].fi,x=fr[i][k].se,y=to[j][l].se;
			if(co>ma && x!=j && y!=i && x!=y){
				ma=co;
				a=x;
				b=i;
				c=j;
				d=y;
			}
		}
	}
	cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
}