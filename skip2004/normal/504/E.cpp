#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
const int maxn = 300300, maxm = 1000100;
const int mod1 = 919601153, mod2 = 925892609, base1 = 19260817, base2 = 12345679;
const int inv1 = 339240035, inv2 = 466031131; 
typedef long long ll;
 
int pw1[maxn],pw2[maxn];
int pinv1[maxn],pinv2[maxn];
struct T{ int to,nxt; } way[maxn << 1];
int ans[maxm << 1];
namespace kth{
	int h[maxn],nxt[maxn];
	struct Q{ int k,nxt; } q[maxm << 1];
	int qh[maxn],num;
	inline void add(int x,int k){ q[++num] = {k,qh[x]},qh[x] = num; }
	int st[maxn],top;
	inline void link(int f,int x){ nxt[x] = h[f],h[f] = x; }
	inline void dfs(int x){
		st[++top] = x;
		for(int i = h[x];i;i = nxt[i]) dfs(i);
		for(int i = qh[x];i;i = q[i].nxt) ans[i] = st[top - q[i].k];
		--top;
	}
}
int h[maxn],num;
inline void link(int x,int y){
	way[++num] = {y,h[x]},h[x] = num;
	way[++num] = {x,h[y]},h[y] = num;
}
int st[20][maxn],dfn[maxn],dep[maxn],fa[maxn],tot;
inline int min(int x,int y) { return dfn[x] < dfn[y] ? x : y; }
inline int lca(int x,int y){
	if(dfn[x] > dfn[y]) std::swap(x,y);
	const int lg = std::__lg(dfn[y] - dfn[x]);
	return x == y ? x : min(st[lg][dfn[x]],st[lg][dfn[y] - (1 << lg)]);
}
typedef std::pair<int,int> pr;
int s1[maxn],s2[maxn];
int v1[maxn],v2[maxn];
inline pr calc1(int s,int t){
	return pr((ll)(v1[s] - v1[fa[t]] + mod1) * pw1[dep[s]] % mod1,(ll)(v2[s] - v2[fa[t]] + mod2) * pw2[dep[s]] % mod2);
}
inline pr calc2(int s,int t){
	return pr((ll)(s1[t] - s1[s] + mod1) * pinv1[dep[s] + 1] % mod1,(ll)(s2[t] - s2[s] + mod2) * pinv2[dep[s] + 1] % mod2);
}
char ch[maxn];
inline void dfs(int x,int f = 0) {
	st[0][tot] = f, dfn[x] = ++ tot, dep[x] = dep[f] + 1,fa[x] = f;
	ch[x] -= 'a';
	s1[x] = (s1[f] + (ll) pw1[dep[x]] * ch[x]) % mod1;
	s2[x] = (s2[f] + (ll) pw2[dep[x]] * ch[x]) % mod2;
	v1[x] = (v1[f] + (ll) pinv1[dep[x]] * ch[x]) % mod1;
	v2[x] = (v2[f] + (ll) pinv2[dep[x]] * ch[x]) % mod2;
	if(f) kth::link(f,x);
	for(int i = h[x];i;i = way[i].nxt) if(way[i].to != f)
		dfs(way[i].to,x);
}
pr hs1[maxm],hs2[maxm];
int a[maxm],b[maxm],c[maxm],d[maxm];
int l[maxm],r[maxm];
int lcaab[maxm],lcacd[maxm];
int disab[maxm],discd[maxm];
int n,m;
char buf[(int) 1e8],*vin = buf - 1;
inline int read(){
	int x,ch;
	while(isspace(ch = * ++vin)); x = ch & 15;
	while(isdigit(ch = * ++vin)) x = x * 10 + (ch & 15);
	return x;
}
char bufo[(int) 2e7],*vout = buf + (int)2e7;
inline void put(int x){ do *--vout = x % 10 + 48; while(x /= 10); }
int main(){
	*pinv1 = *pinv2 = *pw1 = *pw2 = 1;
	for(int i = 1;i < maxn;++i) {
		pinv1[i] = (ll) pinv1[i - 1] * inv1 % mod1;
		pinv2[i] = (ll) pinv2[i - 1] * inv2 % mod2;
		pw1[i] = (ll) pw1[i - 1] * base1 % mod1;
		pw2[i] = (ll) pw2[i - 1] * base2 % mod2;
	}
	fread(buf,1,sizeof buf,stdin);
	n = read();
	for(int i = 1;i <= n;++i) while(isspace(ch[i] = *++vin));
	for(int i = 1;i < n;++i) link(read(),read());
	dfs(1);
	for(int i = 1;i < 20;++i) for(int j = 1;j + (1 << i) - 1 < n;++j)
		st[i][j] = min(st[i - 1][j],st[i - 1][j + (1 << i - 1)]);
	m = read();
	for(int i = 1;i <= m;++i) {
		a[i] = read(),b[i] = read(),c[i] = read(),d[i] = read();
		lcaab[i] = lca(a[i],b[i]);
		lcacd[i] = lca(c[i],d[i]);
		disab[i] = dep[a[i]] + dep[b[i]] - dep[lcaab[i]] * 2;
		discd[i] = dep[c[i]] + dep[d[i]] - dep[lcacd[i]] * 2;
		hs1[i] = calc1(a[i],lcaab[i]);
		hs2[i] = calc1(c[i],lcacd[i]);
		l[i] = -1; r[i] = std::min(disab[i],discd[i]) + 1;
	}
	for(int i = 0;i < 19;++i) {
		for(int i = 1;i <= n;++i) kth::qh[i] = 0; kth::num = 0;
		for(int i = 1;i <= m;++i){
			int mid = l[i] + r[i] >> 1;
			const auto add = [](int a,int b,int lca,int dis,int len){
				if(dep[a] - dep[lca] >= len) kth::add(a,len);
				else kth::add(b,dis - len);
			};
			add(a[i],b[i],lcaab[i],disab[i],mid);
			add(c[i],d[i],lcacd[i],discd[i],mid);
		}
		kth::dfs(1);
		for(int i = 1;i <= m;++i) if(l[i] + 1 != r[i]) {
			const auto get = [](int a,int b,int lca,int dis,int len,int kth,const pr & hs){
				if(dep[a] - dep[lca] >= len) return calc1(a,kth);
				else {
					const pr x = calc2(lca,kth);
					return pr((hs.first + (ll) pw1[dep[a] - dep[lca] + 1] * x.first) % mod1,
							(hs.second + (ll) pw2[dep[a] - dep[lca] + 1] * x.second) % mod2);
				}
			};
			int mid = l[i] + r[i] >> 1;
			if(get(a[i],b[i],lcaab[i],disab[i],mid,ans[i*2-1],hs1[i]) == get(c[i],d[i],lcacd[i],discd[i],mid,ans[i*2],hs2[i]))
				l[i] = mid;
			else
				r[i] = mid;
		}
	}
	for(int i = m;i >= 1;--i) *--vout = 10,put(l[i] + 1);
	fwrite(vout,buf + (int)2e7 - vout,1,stdout);
}