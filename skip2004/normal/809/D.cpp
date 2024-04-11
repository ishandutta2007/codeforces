#include<bits/stdc++.h>
const int maxn = 600200;
int n;
int ls[maxn],rs[maxn],tg[maxn],val[maxn],p[maxn],tot;
void put(int x,int v){ if(x) tg[x] += v,val[x] += v; }
int node(int x){ p[++tot] = rand(),val[tot] = x; return tot; }
void down(int x){ if(tg[x]) put(ls[x],tg[x]),put(rs[x],tg[x]),tg[x] = 0; }
void split(int rt,int v,int&x,int&y){
	if(!rt) x = y = 0;
	else{
		down(rt);
		if(val[rt] <= v) split(rs[rt],v,rs[rt],y),x = rt;
		else split(ls[rt],v,x,ls[rt]),y = rt;
	}
}
int merge(int x,int y){
	if(!x || !y) return x | y;
	if(p[x] > p[y]) return down(x), rs[x] = merge(rs[x],y),x;
	else return down(y), ls[y] = merge(x,ls[y]),y;
}
void erase(int&x){ !ls[x] ? void(x = rs[x]) : erase(ls[x]); }
int main(){
	srand(time(0));
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	std::cin >> n; int rt = 0,ans = 0;
	for(int i = 1,l,r,a,b,c;i <= n;++i){
		std::cin >> l >> r;
		split(rt,r - 1,a,c), split(a,l-1,a,b), put(b,1);
		ans += !c, erase(c), rt = merge(merge(a,node(l)),merge(b,c));
	}
	std::cout << ans << '\n';
}