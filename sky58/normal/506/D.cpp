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
typedef pair<pint,int> tint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define maxv 114514
int data[maxv];
vector<pint> co[maxv];
vector<pint> qu;
vector<tint> q2;
int out[maxv],sum[maxv];
bool sumi[maxv];
vector<int> ed[maxv];
int root(int x){
	return data[x]<0?x:data[x]=root(data[x]);
}
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
void update(pint a){
	//cout<<a.fi<<' '<<a.se<<endl;
	int lo=lower_bound(All(q2),mp(a,-1))-q2.begin(),hi=lower_bound(All(q2),mp(a,maxv))-q2.begin();
	sum[lo]++;sum[hi]--;
}
void dfs(int v){
	//cout<<v<<endl;
	sumi[v]=true;
	rep(i,ed[v].size()){
		if(!sumi[ed[v][i]]) dfs(ed[v][i]);
	}
}
int main()
{
	memset(out,0,sizeof(out));
	memset(sum,0,sizeof(sum));
	memset(sumi,false,sizeof(sumi));
	int n,m,q,a,b,c,bo=200;
	cin>>n>>m;
	rep(i,m){
		cin>>a>>b>>c;a--;b--;c--;co[c].pb(mp(a,b));
	}
	cin>>q;
	rep(i,q){
		cin>>a>>b;a--;b--;qu.pb(mp(a,b));
		if(a>b) swap(a,b);q2.pb(mp(mp(a,b),i));
	}
	sort(All(q2));q2.pb(mp(mp(maxv,maxv),-1));
	rep(i,maxv){
		if(co[i].size()<1) continue;
		//cout<<i<<endl;
		if(co[i].size()>bo){
			memset(data,-1,sizeof(data));
			rep(j,co[i].size()) unions(co[i][j].fi,co[i][j].se);
			rep(j,q){
				if(finds(qu[j].fi,qu[j].se)) out[j]++;
			}
		}
		else{
			set<int> s;
			rep(j,co[i].size()){
				s.insert(co[i][j].fi);s.insert(co[i][j].se);
				ed[co[i][j].fi].pb(co[i][j].se);ed[co[i][j].se].pb(co[i][j].fi);
			}
			vector<int> v(All(s));
			int t=v.size();
			rep(j,t){
				//cout<<v[j]<<endl;
				dfs(v[j]);
				rep(k,t){
					//if(sumi[v[k]]) cout<<v[j]<<' '<<v[k]<<endl;
					if(sumi[v[k]] && k>j){
						//cout<<j<<' '<<k<<' '<<v[j]<<' '<<v[k]<<endl;
						update(mp(v[j],v[k]));
					}
					sumi[v[k]]=false;//ed[v[k]].clear();
				}
				//if(sumi[v[2]]) cout<<j<<endl;
			}
			rep(j,t) ed[v[j]].clear();
		}
	}
	//cout<<'a'<<endl;
	int now=0;
	rep(i,q){
		now+=sum[i];out[q2[i].se]+=now;
	}
	rep(i,q) cout<<out[i]<<endl;
}