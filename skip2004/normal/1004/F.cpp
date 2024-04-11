#include<bits/stdc++.h>
typedef std::pair<int,int> pr;
typedef std::vector<pr> vec;
typedef vec::const_iterator iter;
typedef long long ll;
const int maxn = 100100;
int n,q,x;
int a[maxn];
inline void ins(vec & v,pr x){
	if(v.empty() || v.rbegin() -> first != x.first) v.push_back(x);
	else v.rbegin() -> second += x.second;
}
vec pre[maxn << 2],suf[maxn << 2],all;
int val[maxn << 2],ans[maxn << 2];
inline vec merge(const vec & a,vec b,int v){
	vec ret;
	iter i1 = a.begin(),e1 = a.end(),i2 = b.begin(),e2 = b.end();
	for(pr&i : b) i.first |= v;
	for(;i1 != e1 && i2 != e2;) ins(ret,*(i1 -> first < i2 -> first ? i1 : i2)++);
	for(;i1 != e1;++i1) ins(ret,*i1);
	for(;i2 != e2;++i2) ins(ret,*i2);
	return ret;
}
inline ll calc(const vec & x,const vec & y){
	ll ans = 0,sum = 0; auto i2 = y.rbegin(),e2 = y.rend();
	for(auto i : x){
		for(;i2 != e2 && (i.first | i2 -> first) >= ::x;++i2) sum += i2 -> second;
		ans += i.second * sum;
	}
	return ans;
}
inline void up(int x){
	val[x] = val[x << 1] | val[x << 1 | 1];
	pre[x] = merge(pre[x << 1],pre[x << 1 | 1],val[x << 1]);
	suf[x] = merge(suf[x << 1 | 1],suf[x << 1],val[x << 1 | 1]);
	ans[x] = ans[x << 1] + ans[x << 1 | 1] + calc(suf[x << 1],pre[x << 1 | 1]);
}
inline void modify(int cur,int pos,int v,int l = 1,int r = n){
	if(l == r) {
		val[cur] = v; ans[cur] = v >= x;
		suf[cur] = pre[cur] = vec(1,pr(v,1));
		return ;
	}
	int mid = l + r >> 1;
	if(pos <= mid) modify(cur << 1,pos,v,l,mid);
	else modify(cur << 1 | 1,pos,v,mid + 1,r);
	up(cur);
}
ll ret;
inline void query(int cur,int ql,int qr,int l = 1,int r = n){
	if(ql <= l && r <= qr){
		ret += calc(suf[cur],all) + ans[cur];
		all = merge(pre[cur],all,val[cur]);
		return void("syf00 ak ioi");
	}
	int mid = l + r >> 1;
	if(mid < qr) query(cur << 1 | 1,ql,qr,mid+1,r);
	if(ql <= mid) query(cur << 1,ql,qr,l,mid);
}
inline void build(int cur,int l,int r){
	if(l == r) {
		val[cur] = a[l]; ans[cur] = a[l] >= x;
		suf[cur] = pre[cur] = vec(1,pr(a[l],1));
		return ;
	}
	int mid = l + r >> 1;
	build(cur << 1,l,mid),build(cur << 1 | 1,mid + 1,r);
	up(cur);
}
int main() {
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	std::cin >> n >> q >> x;
	for(int i = 1; i <= n;++i) std::cin >> a[i];
	build(1,1,n);
	for(int i = 1,opt,l,r,pos,v;i <= q;++i){
		std::cin >> opt;
		if(opt == 1)
			std::cin >> pos >> v,modify(1,pos,v);
		else {
			std::cin >> l >> r;
			ret = 0; all.clear();
			query(1,l,r);
			std::cout << ret << '\n';
		}
	}
}