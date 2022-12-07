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
#define maxv 114514
vector<int> gr[maxv],rgr[maxv];
vector<int> vs;
bool sumi[maxv];
int cmp[maxv],num[maxv];
void dfs(int v){
	sumi[v]=true;
	rep(i,gr[v].size()){
		if(!sumi[gr[v][i]]) dfs(gr[v][i]);
	}
	vs.pb(v);
}
void rdfs(int v,int k){
	sumi[v]=true;cmp[v]=k;
	rep(i,rgr[v].size()){
		if(!sumi[rgr[v][i]]) rdfs(rgr[v][i],k);
	}
}
int scc(int v)
{
	memset(sumi,false,sizeof(sumi));
	vs.clear();
	rep(i,v){
		if(!sumi[i]) dfs(i);
	}
	memset(sumi,false,sizeof(sumi));
	int k=0;
	for(int i=vs.size()-1;i>=0;i--){
		if(!sumi[vs[i]]) rdfs(vs[i],k++);
	}
	return k;
}
int dfs2(int v){
	sumi[v]=true;
	int ret=(num[cmp[v]]==1);
	rep(i,gr[v].size()){
		if(!sumi[gr[v][i]]) ret&=dfs2(gr[v][i]);
	}
	rep(i,rgr[v].size()){
		if(!sumi[rgr[v][i]]) ret&=dfs2(rgr[v][i]);
	}
	return ret;
}
int main()
{
	int n,m,out,a,b;
	cin>>n>>m;out=n;
	rep(i,m){
		cin>>a>>b;
		a--;b--;gr[a].pb(b);rgr[b].pb(a);
	}
	m=scc(n);
	memset(num,0,sizeof(num));
	memset(sumi,false,sizeof(sumi));
	rep(i,n) num[cmp[i]]++;
	rep(i,n){
		if(!sumi[i]) out-=dfs2(i);
	}
	cout<<out<<endl;
}