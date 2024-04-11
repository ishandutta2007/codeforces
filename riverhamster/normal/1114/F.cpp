#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
const int PS = 300, PL = 305, N = 400000 * 4 + 5;
bool np[PL];
int ps = 0;
ll p[PL], invp[PL];
ll qp(ll a, int b){
	ll ans = 1;
	while(b){
		if(b&1) ans = (ans * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ans;
}
void prime_list(int n){
	for(int i=2; i<=n; i++){
		if(!np[i]){
			p[ps++] = i;
			invp[ps-1] = qp(i, mod-2);
		}
		for(int j=i*i; j<=n; j+=i) np[j] = true;
	}
}
ll getfac(int x){
	ll ans = 0;
	for(int i=0; i<ps; i++)
		if(x % p[i] == 0) ans |= (1LL << i);
	return ans;
}
ll ediv(ll x){
	ll ans = 1;
	for(int i=0; i<ps; i++)
		if(x & (1LL << i)) ans = ans * (p[i]-1) % mod * invp[i] % mod;//, printf("* %d / %d\n", p[i]-1, p[i]);
	return ans;
}
#define root 1, 1, n
#define ls (x<<1)
#define rs ((x<<1)|1)
#define lson ls, l, mid
#define rson rs, mid+1, r
ll v[N], fac[N], mt[N], ft[N];
inline void upd(int x){v[x] = v[ls] * v[rs] % mod; fac[x] = fac[ls] | fac[rs];}
inline void pd(int x, int llen, int rlen){
	if(mt[x]!=1){
		// printf("pd mt[%d] = %lld\n", x, mt[x]);
		v[ls] = (v[ls] * qp(mt[x], llen)) % mod; v[rs] = v[rs] * qp(mt[x], rlen) % mod;
		mt[ls] = (mt[ls] * mt[x]) % mod; mt[rs] = (mt[rs] * mt[x]) % mod;
		mt[x] = 1;
	}
	if(ft[x]){
		// printf("pd ft[%d] = %lld\n", x, ft[x]);
		fac[ls] |= ft[x]; fac[rs] |= ft[x];
		ft[ls] |= ft[x]; ft[rs] |= ft[x];
		ft[x] = 0;
	}
}
void build(int x, int l, int r){
	// printf("build x %d l %d r %d\n", x, l, r);
	mt[x] = 1; ft[x] = 0;
	if(l == r){
		in(v[x]);
		fac[x] = getfac(v[x]);
		// printf("final v[%d] = %lld fac[%d] = %lld\n", x, v[x], x, fac[x]);
		// mt[x] = 1; ft[x] = 0;
		return ;
	}
	int mid = (l + r) >> 1;
	build(lson); build(rson);
	upd(x);
	// printf("v[%d] = %lld fac[%d] = %lld\n", x, v[x], x, fac[x]);
}
void edit(int x, int l, int r, int a, int b, ll Mul, ll Fac){
	if(a <= l && b >= r){
		v[x] = v[x] * qp(Mul, r-l+1) % mod; mt[x] = mt[x] * Mul % mod;
		fac[x] |= Fac; ft[x] |= Fac;
		return ;
	}
	int mid = (l + r) >> 1;
	pd(x, mid-l+1, r-mid);
	if(a <= mid) edit(lson, a, b, Mul, Fac);
	if(b > mid)  edit(rson, a, b, Mul, Fac);
	upd(x);
}
pair<ll, ll> query(int x, int l, int r, int a, int b){
	if(a <= l && b >= r) return make_pair(v[x], fac[x]);
	int mid = (l + r) >> 1;
	pd(x, mid-l+1, r-mid);
	pair<ll, ll> ans = make_pair(1ll, 0ll), t;
	if(a <= mid){
		t = query(lson, a, b);
		ans.first = (ans.first * t.first) % mod;
		ans.second |= t.second;
	}
	if(b > mid){
		t = query(rson, a, b);
		ans.first = (ans.first * t.first) % mod;
		ans.second |= t.second;
	}
	return ans;
}

int main(){
	// freopen("cf1114f.in", "r", stdin);
	// freopen("cf1114f.out", "w", stdout);
	prime_list(300);
	// printf("ps = %d\n", ps);
	int n, q, l, r, x;
	in(n); in(q);
	// printf("n = %d\n", n);
	for(int i=0; i<=n*4; i++) v[i] = 1;
	build(root);
	static char op[30];
	pair<ll, ll> res;
	while(q--){
		scanf("%s", op); in(l); in(r);
		if(op[0] == 'M'){
			in(x);
			edit(root, l, r, x, getfac(x));
		} else{
			res = query(root, l, r);
			// printf("res.first = %lld ediv(%lld) = %lld\n", res.first, res.second, ediv(res.second));
			printf("%lld\n", res.first * ediv(res.second) % mod);
		}
	}
	return 0;
}