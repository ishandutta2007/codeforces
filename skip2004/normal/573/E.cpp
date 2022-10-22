#include<bits/stdc++.h>
const int N = 100100;
typedef long long ll;
std::mt19937 rd(time(0));
int ls[N],rs[N],sz[N],p[N],rt,n,tot;
ll v[N],ad[N],tg[N];
int nd(ll a){ return p[++tot]=rd(), sz[tot] = 1, v[tot] = a,tot; }
void up(int x){ sz[x] = sz[ls[x]] + sz[rs[x]] + 1; }
void pt1(int x,ll t){ if(x) v[x] += t, ad[x] += t; }
void pt2(int x,ll t){ if(x) v[x] += t * sz[ls[x]], tg[x] += t; }
void dw(int x){
	if(ad[x]) pt1(ls[x],ad[x]),pt1(rs[x],ad[x]),ad[x]=0;
	if(tg[x]) pt2(ls[x],tg[x]),pt2(rs[x],tg[x]),pt1(rs[x],(sz[ls[x]]+1ll)*tg[x]),tg[x]=0;
}
void split(int rt,int k,int&x,int&y){
	if(!rt) x = y = 0;
	else{
		dw(rt);
		if(k<=sz[ls[rt]])split(ls[rt],k,x,ls[rt]),up(y=rt);
		else split(rs[rt],k-sz[ls[rt]]-1,rs[rt],y),up(x=rt);
	}
}
int merge(int x,int y){
	if(!x||!y)return x|y;
	if(p[x]>p[y]){
		dw(x),rs[x]=merge(rs[x],y),up(x);
		return x;
	}else{
		dw(y),ls[y]=merge(x,ls[y]),up(y);
		return y;
	}
}
ll kth(int rt,int k){
	dw(rt);
	if(k <= sz[ls[rt]]) return kth(ls[rt],k);
	return sz[ls[rt]] + 1 == k ? v[rt] : kth(rs[rt],k-sz[ls[rt]]-1);
}
ll kth(int k){ return k ? kth(rt,k) : 0; }
ll mx(int rt){ return rt ? dw(rt),std::max(v[rt],std::max(mx(ls[rt]),mx(rs[rt]))) : 0; }
int main(){
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	std::cin >> n; rt = merge(nd(-1e18),nd(-1e18));
	for(int i=1,x;i<=n;++i){
		std::cin >> x;
		int l = -1,r = i,a,b;
		while(l + 1 != r){
			ll mid = l + r >> 1;
			if(kth(mid) + x * (mid + 1) > kth(mid + 1)) r = mid;
			else l = mid;
		} l = r;
		if(l){
			split(rt,l-1,a,b); 
			rt = merge(a,nd(kth(b,1)));
			pt1(b,x * (l + 1ll)); pt2(b,x);
			rt = merge(rt,b);
		}else{
			pt1(rt,x + x); pt2(rt,x);
			rt = merge(nd(x),rt);
		}
	}
	std::cout << mx(rt) << '\n';
}