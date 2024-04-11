#include<bits/stdc++.h>
const int maxn = 200200;
int mod;
typedef long long ll;
inline ll pow(ll a,int b,ll ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1) ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
inline void reduce(int & x){ x += x >> 31 & mod; }
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
typedef long long ll;
struct T {
	int a[2][2];
	inline T operator * (const T&y) const {
		T ret;
		for(int i = 0;i < 2;++i) for(int j = 0;j < 2;++j) 
			ret.a[i][j] = ((ll) a[i][0] * y.a[0][j] + (ll) a[i][1] * y.a[1][j]) % mod;
		return ret;
	}
};
std::map<ll, int> vec;
std::vector<std::pair<ll, int>> vc;
ll k; int n, m;
T tree[maxn << 2];
inline void mdf(int o,int pos,const T & x,int l = 0,int r = n - 1) {
	if(l == r) return void(tree[o] = x);
	int mid = l + r >> 1;
	if(pos <= mid) mdf(o << 1,pos,x,l,mid);
	else mdf(o << 1 | 1,pos,x,mid+1,r);
	tree[o] = tree[o << 1] * tree[o << 1 | 1];
}
inline T qry(int o,int ql,int qr,int l = 0,int r = n - 1) {
	if(ql <= l && r <= qr) return tree[o];
	int mid = l + r >> 1; T ans = {1,0,0,1};
	if(ql <= mid) ans = ans * qry(o << 1,ql,qr,l,mid);
	if(mid < qr) ans = ans * qry(o << 1 | 1,ql,qr,mid+1,r);
	return ans;
}
int s[maxn];
inline int get(ll x) { return vec.count(x) ? vec[x] : s[(x + n) % n]; }
inline T val(ll pos){ return {0 , get(pos - 1), 1, get(pos)}; }
inline void build(int cur,int l,int r) {
	if(l == r) return void(tree[cur] = val(l));
	int mid = l + r >> 1;
	build(cur << 1,l,mid), build(cur << 1 | 1,mid + 1,r);
	tree[cur] = tree[cur << 1] * tree[cur << 1 | 1];
}
inline T pow(T a,ll b,T ans = {1,0,0,1}){
	for(;b;b>>=1,a=a*a)if(b&1)ans=ans*a;
	return ans;
}
inline T qry(ll l,ll r) {
	if(l > r) return {1,0,0,1};
	if(l / n == r / n) return qry(1, l % n, r % n);
	return qry(1,l % n, n - 1) * pow(tree[1], r / n - l / n - 1) * qry(1,0,r % n);
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> k >> mod >> n;
	for(int i = 0;i < n;++i) std::cin >> s[i], s[i] %= mod;
	std::cin >> m;
	for(int i = 0;i < m;++i) {
		ll j; int v;
		std::cin >> j >> v;
		vec[j] = v;
		vc.emplace_back(j, v);
	}
	build(1,0, n - 1);
	for(auto i : vc)if(!vec.count(i.first+n)) vec[i.first+n]=s[i.first%n];
	T ans = {0, 1, 0, 0};
	ll now = 0;
	for(const auto& i : vec) {
		ans = ans * qry(now + 1,std::min(i.first - 1, k));
		now = i.first;
		if(i.first > k) break;
		mdf(1, (i.first + 0) % n, val(i.first + 0));
		mdf(1, (i.first + 1) % n, val(i.first + 1));
		ans = ans * val(i.first);
	}
	ans = ans * qry(now + 1,k);
	std::cout << ans.a[0][0] << '\n';
}