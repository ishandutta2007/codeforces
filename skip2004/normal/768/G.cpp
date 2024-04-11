 
#include<bits/stdc++.h>
const int maxn = 100100;
using std::max; using std::min;
struct Tree{
	// it can be O(loglogn)
	std::multiset<int> s;
	inline void ins(int x){ s.insert(x); }
	inline void del(int x){ s.erase(s.find(x)); }
	inline int calc(int mx,int mn,int dt = 0){
		int ret = mx;
		std::multiset<int>::iterator it = s.lower_bound(mx - mn + dt + dt >> 1);
		if(it != s.end()) ret = min(ret,max(mx - (*it - dt),mn + (*it - dt)));
		if(it != s.begin()) --it,ret = min(ret,max(mx - (*it - dt),mn + (*it - dt)));
		return ret;
	}
	void swap(Tree & y){ s.swap(y.s); }
	void ins(Tree & y){
		if(s.size() < y.s.size()) swap(y);
		s.insert(y.s.begin(),y.s.end()), y.s.clear();
	}
};
struct T{ int to,nxt; } way[maxn << 1];
int h[maxn],num;
inline void adde(int x,int y){
	way[++num] = {y,h[x]},h[x] = num;
	way[++num] = {x,h[y]},h[y] = num;
}
int size[maxn],ans[maxn],son[maxn],out[maxn],n;
void dfs0(int x,int f = 0){
	size[x] = 1;
	for(int i = h[x];i;i=way[i].nxt) if(way[i].to != f) {
		dfs0(way[i].to,x), size[x] += size[way[i].to];
		if(size[way[i].to] > size[son[x]]) son[x] = way[i].to;
	}
}
Tree s0,s1,s[maxn];
void remove(int x,int f){ s0.del(size[x]); for(int i = h[x];i;i=way[i].nxt) if(way[i].to != f) remove(way[i].to,x); }
void insert(int x,int f){ s0.ins(size[x]); for(int i = h[x];i;i=way[i].nxt) if(way[i].to != f) insert(way[i].to,x); }
void dfs1(int x,int f){
	const int sf = n - size[x];
	if(f) s0.del(size[x]); s1.ins(size[x]);
	int min = f ? n - size[x] : 1e9,mx = n - size[x];
	for(int i = h[x];i;i=way[i].nxt) if(way[i].to != f && way[i].to != son[x]) {
		dfs1(way[i].to,x); insert(way[i].to,x);
		min = std::min(min,size[way[i].to]);
		mx = std::max(mx,size[way[i].to]);
	}
	if(son[x]) dfs1(son[x],x),min = std::min(min,size[son[x]]);
	for(int i = h[x];i;i=way[i].nxt) if(way[i].to != f && way[i].to != son[x]) remove(way[i].to,x);
	out[x] = f ? max(std::min(s0.calc(sf,min),s1.calc(sf,min,size[x])),size[son[x]]) : 1e9;
	if(son[x]) out[x] = std::min(out[x],max(s[son[x]].calc(size[son[x]],min),mx));
	for(int i = h[x];i;i=way[i].nxt) if(way[i].to != f) s[x].ins(s[way[i].to]);
	if(f) s[x].ins(size[x]); s1.del(size[x]);
}
int main(){
    int rt = 0;
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	std::cin >> n;
	if(n == 1){
	  std::cout << 0 << '\n';
	  return 0;
	}
	for(int i = 1,x,y;i <= n;++i) std::cin >> x >> y,x ? adde(x,y) : void(rt = y);
	dfs0(rt);
	for(int i = 1;i <= n;++i) if(i!=rt) s0.ins(size[i]);
	dfs1(rt,0);
	for(int i = 1;i <= n;++i) std::cout << out[i] << '\n';
}