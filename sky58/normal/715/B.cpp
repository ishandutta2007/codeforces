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
typedef pair<lint,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
vector<int> ze;
vector<int> gr[1010];
int u[11451],v[11451];
lint w[11451];
lint dp[1010];
bool sumi[1010];
int inf=1145141919;
priority_queue<pint> q;
int s,t;
void aedge(int x,lint y){
	if(dp[x]<=y) return;
	dp[x]=y;q.push(mp(-y,x));
}
lint cal(lint T){
	rep(i,ze.size()){
		w[ze[i]]=T/ze.size()+1;
		if(i<(int)(T%ze.size())) w[ze[i]]++;
	}
	memset(sumi,false,sizeof(sumi));
	rep(i,1010) dp[i]=inf;
	aedge(s,0);
	while(!q.empty()){
		pint p=q.top();q.pop();
		int x=p.se;lint y=-p.fi;
		if(sumi[x]) continue;sumi[x]=true;
		rep(i,gr[x].size()) aedge(u[gr[x][i]],y+w[gr[x][i]]),aedge(v[gr[x][i]],y+w[gr[x][i]]);
	}
	return dp[t];
}
int main()
{
	int n,m,l,W;lint L;
	scanf("%d %d %d %d %d",&n,&m,&l,&s,&t);L=l;
	rep(i,m){
		scanf("%d %d %d",&u[i],&v[i],&W);
		if(W==0) ze.pb(i);
		gr[u[i]].pb(i);gr[v[i]].pb(i);
		w[i]=W;
	}
	if(cal(0)>L || cal(1145141919810893LL)<L){
		cout<<"NO"<<endl;return 0;
	}
	lint lo=0,hi=1145141919810893LL;
	while(lo<hi){
		lint mi=(hi+lo)/2;
		if(cal(mi)>=L) hi=mi;else lo=mi+1;
	}
	cal(lo);cout<<"YES"<<endl;
	rep(i,m) printf("%d %d %d\n",u[i],v[i],(int)w[i]);
}