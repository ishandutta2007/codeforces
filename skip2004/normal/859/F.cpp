
#include<bits/stdc++.h>
const int maxn = 400100;
typedef long long ll;
int n,t;
ll c;
int s[maxn];
ll dp[maxn];
namespace sg{
	ll gx[maxn << 2],sx[maxn << 2],is_c[maxn << 2],tg[maxn << 2];
	inline void put(int cur,ll v){ gx[cur] += v, sx[cur] += v, tg[cur] += v; }
	void clear(int cur,int l = 1,int r = n){
		gx[cur] = sx[cur] = is_c[cur] = tg[cur] = 0;
		if(l == r) return ;
		int mid = l + r >> 1;
		clear(cur << 1,l,mid); clear(cur << 1 | 1,mid + 1,r);
	}
	inline void update(int cur){
		gx[cur] = std::max(gx[cur << 1],gx[cur << 1 | 1]);
		sx[cur] = std::max(sx[cur << 1],sx[cur << 1 | 1]);
		is_c[cur] = is_c[cur << 1] && is_c[cur << 1 | 1];
	}
	inline void pushdown(int cur){ put(cur << 1,tg[cur]); put(cur << 1 | 1,tg[cur]); tg[cur] = 0; }
	inline void add(int cur,int ql,int qr,ll v,int l = 1,int r = n){
		if(is_c[cur]) return ;
		if(ql <= l && r <= qr){
			if(gx[cur] + v <= c) return put(cur,v);
			if(l == r) {
				sx[cur] -= gx[cur], sx[cur] += gx[cur] = c, is_c[cur] = 1;
				return ;
			}
		}
		int mid = l + r >> 1; pushdown(cur);
		if(ql <= mid) add(cur << 1,ql,qr,v,l,mid);
		if(mid < qr) add(cur << 1 | 1,ql,qr,v,mid + 1,r);
		update(cur);
	}
	inline void mdf(int cur,int pos,ll s,ll g,int l = 1,int r = n){
		if(l == r) return void((gx[cur] = g,sx[cur] = s + g));
		int mid = l + r >> 1; pushdown(cur);
		if(pos <= mid) mdf(cur << 1,pos,s,g,l,mid);
		else mdf(cur << 1 | 1,pos,s,g,mid + 1,r);
		update(cur);
	}
}
int main(){
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	std::cin >> n >> c;
	for(int i = 1;i <= n * 2 - 1;++i) std::cin >> s[i];
	sg::clear(1);
	for(int i = 1;i <= n;++i){
		if(i - 1) sg::add(1,1,i - 1,s[i * 2 - 1] + s[i * 2 - 2]);
		sg::mdf(1,i,dp[i - 1],std::min<ll>(c,s[i * 2 - 1]));
		dp[i] = sg::sx[1];
	}
	std::cout << dp[n] << '\n';
}