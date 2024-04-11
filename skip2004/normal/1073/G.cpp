#include<bits/stdc++.h>
typedef long long ll;
const int maxn = 400100;
char buf[maxn];
int n,q;
namespace sam{
	int c[maxn][26],mx[maxn],fa[maxn],r[maxn],la,tot;
	int n,q;
	inline void ins(int w,int id){
		int p=la,now=la=++tot; mx[now] = mx[p] + 1; r[id] = tot;
		for(;p && !c[p][w];p = fa[p]) c[p][w] = now;
		if(!p) fa[now] = 1;
		else {
			int q = c[p][w];
			if(mx[q] == mx[p] + 1) fa[now] = q;
			else {
				int x = ++ tot; fa[x] = fa[q]; mx[x] = mx[p] + 1;
				memcpy(c[x],c[q],sizeof c[x]); fa[q] = fa[now] = x;
				for(;p && c[p][w] == q;p = fa[p]) c[p][w] = x;
			}
		}
	}
}
struct T{ int to,nxt; }way[maxn];
int h[maxn],num;
inline void adde(int x,int y){ way[++num]={y,h[x]},h[x]=num; }
int size[maxn],dfn[maxn],fa[maxn],dep[maxn],st[20][maxn],idx;
inline void dfs(int x){
	size[x] = 1,st[0][dfn[x] = ++ idx] = x,dep[x] = dep[fa[x]] + 1;
	for(int i=h[x];i;i=way[i].nxt)
		fa[way[i].to]=x,dfs(way[i].to), size[x] += size[way[i].to];
	st[0][idx] = fa[x];
}
inline int min(int x,int y){ return dep[x] < dep[y] ? x : y; }
inline int lca(int x,int y){
	if(dfn[x] > dfn[y]) std::swap(x,y);
	const int lg = 31 - __builtin_clz(dfn[y] - dfn[x]);
	return x == y ? x : min(st[lg][dfn[x]],st[lg][dfn[y] - (1<<lg)]);
}
ll ans = 0;
namespace vt{
	struct T{ int to,nxt; }way[maxn << 1];
	int h[maxn],num;
	int c1[maxn],c2[maxn];
	inline void adde(int x,int y){ way[++num]={y,h[x]},h[x]=num; }
	inline void dfs(int x,int f = 0){
		for(int & i = h[x];i;i=way[i].nxt)
			dfs(way[i].to,x),c1[x] += c1[way[i].to],c2[x] += c2[way[i].to];
		ans += ll(sam::mx[x] - sam::mx[f]) * c1[x] * c2[x];
	}
}
inline int cmp(int x,int y){ return dfn[x] < dfn[y]; }
int main(){
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	std::cin >> n >> q >> buf + 1; sam::la=sam::tot=1;
	for(int i=n;i>=1;--i) sam::ins(buf[i] - 'a',i);
	for(int i=2;i<=sam::tot;++i){
		adde(sam::fa[i],i);
	}
	dfs(1);
	for(int i=1;i<20;++i) for(int j=1;j+(1<<i)-1<sam::tot;++j)
		st[i][j]=min(st[i-1][j],st[i-1][j+(1<<i-1)]);
	for(int i=1;i<=q;++i){
		int n1,n2; std::vector<int> v; std::cin >> n1 >> n2;
		for(int i=1,x;i<=n1;++i) std::cin >> x,x = sam::r[x],vt::c1[x] = 1,v.push_back(x);
		for(int i=1,x;i<=n2;++i) std::cin >> x,x = sam::r[x],vt::c2[x] = 1,v.push_back(x);
		std::sort(v.begin(),v.end(),cmp),v.erase(std::unique(v.begin(),v.end()),v.end());
		for(int i=0,s=v.size();i+1<s;++i) v.push_back(lca(v[i],v[i+1]));
		std::sort(v.begin(),v.end(),cmp),v.erase(std::unique(v.begin(),v.end()),v.end());
		static int st[maxn]; int top = 1; st[top] = v[0]; vt::num = 0;
		for(int i=1;i<v.size();++i){
			while(top > 1 && dfn[v[i]] >= dfn[st[top]] + size[st[top]]) -- top;
			vt::adde(st[top],v[i]); st[++top] = v[i];
		}
		ans = 0,vt::dfs(v[0]),std::cout << ans << '\n';
		for(int i=0;i<v.size();++i) vt::c1[v[i]] = vt::c2[v[i]] = 0;
	}
}