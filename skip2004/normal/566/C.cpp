#include<bits/stdc++.h>
const int maxn = 200200;
typedef long double db;
db ans; int pos,n;
struct T{ int to,nxt,v; }way[maxn << 1];;
int h[maxn],num;
int vis[maxn],w[maxn];
inline void link(int x,int y,int v){
	way[++num]={y,h[x],v},h[x] = num;
	way[++num]={x,h[y],v},h[y] = num;
}
db calc(int x,int f = 0,db s = 0){
	db ret = s * sqrtl(s) * w[x];
	for(int i = h[x];i;i=way[i].nxt)if(way[i].to != f) ret += calc(way[i].to,x,s + way[i].v);
	return ret;
}
db calc2(int x,int f = 0,db s = 0){
	db ret = 1.5 * sqrtl(s) * w[x];
	for(int i = h[x];i;i=way[i].nxt)if(way[i].to != f) ret += calc2(way[i].to,x,s + way[i].v);
	return ret;
}
int size[maxn];
inline void getsz(int x,int f=0){
	size[x] = 1;
	for(int i = h[x];i;i=way[i].nxt) if(!vis[way[i].to] && way[i].to != f)
		getsz(way[i].to,x),size[x] += size[way[i].to];
}
int mn,rt;
inline void getrt(int x,int sz,int f = 0){
	int mx = sz - size[x];
	for(int i = h[x];i;i=way[i].nxt) if(!vis[way[i].to] && way[i].to != f)
		getrt(way[i].to,sz,x),mx = std::max(mx,size[way[i].to]);
	if(mx < mn) mn = mx,rt = x;
}
inline int getroot(int x){
	mn = 1e9, getsz(x),getrt(x,size[x]);
	return rt;
}
inline void dfs(int x){
	typedef std::pair<db,int> pr;
	std::vector<pr> v;
	x = getroot(x); vis[x] = 1;
	for(int i = h[x];i;i=way[i].nxt) if(!vis[way[i].to])
		v.emplace_back(calc2(way[i].to,x,way[i].v),way[i].to);
	std::sort(v.rbegin(),v.rend());
	db p = calc(x);
	if(p < ans) ans = p,pos = x;
	if(v.size()) dfs(v.begin() -> second);
}
int main(){
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	std::cin >> n;
	for(int i = 1;i <= n;++i) std::cin >> w[i];
	for(int i = 1,x,y,v;i<n;++i) std::cin >> x >> y >> v,link(x,y,v);
	ans = 1e50;
	dfs(1);
	std::cout << pos << ' ' << std::setprecision(20) << ans << '\n';
}