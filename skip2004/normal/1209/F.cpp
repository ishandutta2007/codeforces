#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#include<bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
using namespace __gnu_pbds;
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2001000;
inline void flush(){cout.flush(),fflush(stdout);}
typedef unsigned long long u64;
typedef unsigned u32;
typedef long long ll;
typedef long double ld;
template<typename t>using heap=__gnu_pbds::priority_queue<t>;
template<typename t>using rbt=tree<t,null_type,less<t>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename t>inline istream&operator,(istream&cin,t&x){return cin>>x;}
template<typename t>inline ostream&operator,(ostream&cout,const t&x){return cout<<x;}
template<typename _1,typename _2>inline void up(_1&a,const _2&b){if(a<b)a=b;}
template<typename _1,typename _2>inline void down(_1&a,const _2&b){if(a>b)a=b;}
istream&in=cin;ostream&out=cout;
inline int pow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=ll(a)*a%mod)
        if(b&1)ans=ll(ans)*a%mod;
    return ans;
}
inline int inv(int a){return pow(a,mod-2);}
int n,m;
struct T{ int to,nxt,v; } way[maxn << 1];
int h[maxn],num=1;
inline void adde(int x,int y,int v){
	way[++num]={y,h[x],v},h[x]=num;
	way[++num]={x,h[y],v},h[y]=num;
}
typedef pair<int,int> pr;
int dis[maxn],vis[maxn];
inline void dij(){
	std::priority_queue<pr,vector<pr>,greater<pr>> q;
	for(int i=2;i<=n;++i) dis[i] = 1e9;
	for(q.push(pr(0,1));!q.empty();){ pr t = q.top(); q.pop(); if(vis[t.second]) continue;
		vis[t.second]=1; int x=t.second; for(int i=h[x];i;i=way[i].nxt)
			if(dis[way[i].to] > dis[x] + way[i].v){
				dis[way[i].to] = dis[x] + way[i].v;
				q.push(pr(dis[way[i].to],way[i].to));
			}
	}
}
inline int calc(int x){ return x <= 9 ? 1 : calc(x / 10) + 1; }
inline int c2(int x){ return x <= 9 ? 10 : c2(x / 10) * 10; }
namespace dag{
	std::vector<int> to[maxn][10];
	int vis[maxn];
	int dis[maxn];
	int tot;
	inline void link(int x,int y,int v){
		auto s = std::to_string(v);
		for(char&i : s)
			to[x][i - 48].push_back(& i == &*s.rbegin() ? y : ++tot), x = tot;
	}
	std::vector<int> q[maxn]; int t;
	inline void solve(){
		q[0].push_back(1); vis[1] = 1; t = 1;
		for(int i=0;i<t;++i){
			for(int j=0;j<10;++j){
				for(int k : q[i]) for(int l : to[k][j])if(!vis[l]){
					vis[l] = 1; dis[l] = (dis[k] * 10ll + j) % mod;
					q[t].push_back(l);
				}
				if(q[t].size()) ++ t;
			}
		}
		for(int i=2;i<=n;++i) std::cout << dis[i] << '\n';
	}
}
int rk[maxn];
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	in,n,m;
	rep(i,1,m){
		int x,y; in,x,y;
		adde(x,y,calc(i));
	}
	dij(); dag::tot = n;
	for(int i=1;i<=n;++i) rk[i] = i;
	std::sort(rk + 1,rk + n + 1,[](int x,int y){ return dis[x] < dis[y]; });
	for(int j=1;j<=n;++j){
		int x = rk[j];
		for(int i=h[x];i;i=way[i].nxt)if(dis[way[i].to] == dis[x] + way[i].v)
			dag::link(x,way[i].to,i>>1);
	}
	dag::solve();
}