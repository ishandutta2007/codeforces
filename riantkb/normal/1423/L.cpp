#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#include<cassert>
#include<random>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (int)(Y);++(X))
#define reps(X,S,Y) for (int (X) = (int)(S);(X) < (int)(Y);++(X))
#define rrep(X,Y) for (int (X) = (int)(Y)-1;(X) >=0;--(X))
#define rreps(X,S,Y) for (int (X) = (int)(Y)-1;(X) >= (int)(S);--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define Endl endl
#define NL <<"\n"
#define cauto const auto

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
template<class T> using vv=vector<vector<T>>;
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
//#undef NUIP
#ifdef NUIP
#include "benri.h"
#else
#define out(args...)
#endif
#ifdef __cpp_init_captures
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
#endif
template<class A,class B> pair<A,B> operator+(const pair<A,B> &p,const pair<A,B> &q){ return {p.X+q.X,p.Y+q.Y};}
template<class A,class B,class C,class D> pair<A,B>& operator+=(pair<A,B> &p,const pair<C,D> &q){ p.X+=q.X; p.Y+=q.Y; return p;}
template<class A,class B> pair<A,B> operator-(const pair<A,B> &p,const pair<A,B> &q){ return {p.X-q.X,p.Y-q.Y};}
template<class A,class B,class C,class D> pair<A,B>& operator-=(pair<A,B> &p,const pair<C,D> &q){ p.X-=q.X; p.Y-=q.Y; return p;}
template<class A,class B> istream& operator>>(istream &is, pair<A,B> &p){ is>>p.X>>p.Y; return is;}
template<class T=ll> T read(){ T re; cin>>re; return move(re);}
template<class T=ll> T read(const T &dec){ T re; cin>>re; return re-dec;}
template<class T=ll> vector<T> readV(const int sz){ vector<T> re(sz); for(auto &x:re) x=read<T>(); return move(re);}
template<class T=ll> vector<T> readV(const int sz, const T &dec){ vector<T> re(sz); for(auto &x:re) x=read<T>(dec); return move(re);}
vv<int> readG(const int &n,const int &m){ vv<int> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); g[a].pb(b); g[b].pb(a);} return move(g);}
vv<int> readG(const int &n){ return readG(n,n-1);}
const ll MOD=1e9+7; //998244353

using BS=bitset<1000>;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	read();
	cauto s=read();
	cauto d=read();
	vector<BS> cs(s),ts(d);
	rep(i,s){
		int t;
		cin>>t;
		rep(_,t){
			int x;
			cin>>x; --x;
			cs[i][x]=1;
		}
	}
	rep(i,d){
		int t;
		cin>>t;
		rep(_,t){
			int x;
			cin>>x; --x;
			ts[i][x]=1;
		}
	}

	vector<BS> bases;
	vector<int> deps,bss_;
	rep(i,cs.size()){
		auto c=cs[i];
		for(auto b:bases)if(c[b._Find_first()]) c^=b;
		if(c.none()){
			deps.eb(i);
			continue;
		}
		cauto d=c._Find_first();
		for(auto &b:bases)if(b[d]) b^=c;
		bases.eb(c);
		bss_.eb(i);
	}
	vector<int> ds(s);
	vector<int> es(d);
	rep(i,bases.size()){
		cauto D=bases[i]._Find_first();
		rep(j,s)if(cs[j][D]) ds[j]|=1<<i;
		rep(j,d)if(ts[j][D]) es[j]|=1<<i;
	}
	for(auto &i:bss_) i=ds[i];

	out(bases,deps,bss_,ds,es,1);

	vector<int> dist;
	vector<pii> bss;
	if(bases.size()<=20,0){
		const int B=bases.size();
		dist.resize(1<<B,MOD); dist[0]=0;
		queue<int> que; que.emplace(0);
		while(que.size()){
			int x=que.front(); que.pop();
			for(auto d:ds)if(MN(dist[x^d],dist[x]+1)) que.emplace(x^d);
		}
	}else{
		const int N=bss_.size();
		bss.resize(N);
		rep(i,N) bss[i]={bss_[i],1<<i};
		rep(i,N){
			reps(j,i,N)if(~bss[j].X>>i){
				swap(bss[j],bss[i]);
				break;
			}
			rep(j,N)if(i!=j && bss[j].X>>i&1){
				bss[j].X^=bss[i].X;
				bss[j].Y^=bss[i].Y;
			}
		}
	}

	out(dist,bss,1);

	vector<int> re(d,-1);
	rep(i,d){
		BS bs; bs.reset();
		rep(j,bases.size())if(es[i]>>j&1) bs^=bases[j];
		if(bs!=ts[i]) continue;
		if(dist.size()){
			re[i]=dist[es[i]];
			continue;
		}
		const int N=deps.size();
		re[i]=MOD;
		rep(st,1<<N){
			auto rem=es[i];
			rep(j,N)if(st>>j&1) rem^=ds[deps[j]];
			int x=0;
			rep(j,bss.size())if(rem>>j&1) x^=bss[j].Y;
			int sz=__builtin_popcount(st);
			sz+=__builtin_popcount(x);
			MN(re[i],sz);
		}
	}
	out(re,1);
	for(cauto x:re) cout<<x NL;
  return 0;
}