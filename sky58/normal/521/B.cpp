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
map<pint,int> me;
set<int> zero;
int top[114514],bot[114514],x[114514],y[114514];
bool sumi[114514];
vector<int> v1[114514],v2[114514];
lint zyo[114514];
void rem(int id){
	sumi[id]=true;
	if(bot[id]==1){
		rep(j,v1[id].size()){
			int v=v1[id][j];top[v]--;
			if(top[v]==0 && !sumi[v]) zero.insert(v);
		}
	}
	rep(j,v2[id].size()){
		int v=v2[id][j];
		bot[v]--;
		if(bot[v]==1 && !sumi[v]){
			rep(k,v1[v].size()){
				int w=v1[v][k];top[w]++;
				if(top[w]==1 && !sumi[w]) zero.erase(w);
			}
		}
	}
}
int main()
{
	int n;lint mo=1000000009,out=0;
	cin>>n;
	rep(i,n){
		cin>>x[i]>>y[i];
		me[mp(x[i],y[i])]=i;
	}
	zyo[0]=1;rep(i,100100) zyo[i+1]=(zyo[i]*n)%mo;
	memset(sumi,false,sizeof(sumi));
	memset(bot,0,sizeof(bot));
	memset(top,0,sizeof(top));
	rep(i,n){
		if(y[i]==0) bot[i]=114514;
		else{
			rep(j,3){
				if(me.count(mp(x[i]+1-j,y[i]-1))) bot[i]++,v1[i].pb(me[mp(x[i]+1-j,y[i]-1)]);
			}
		}
	}
	rep(i,n){
		rep(j,3){
			if(me.count(mp(x[i]+1-j,y[i]+1))){
				int it=me[mp(x[i]+1-j,y[i]+1)];
				v2[i].pb(it);
				if(bot[it]==1) top[i]++;
			}
		}
		if(top[i]<1) zero.insert(i);
	}
	//rep(i,n) cerr<<bot[i]<<' '<<top[i]<<endl;
	rep(i,n){
		set<int>::iterator it;
		if(i%2==0){
			it=zero.end();it--;
		}
		else it=zero.begin();
		int id=(*it);zero.erase(it);rem(id);
		//cerr<<id<<endl;
		out=(out+zyo[n-1-i]*id)%mo;
	}
	cout<<out<<endl;
}