#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> 
#include<ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef long double ld;

template <typename A, typename B = less<A>> using ordered_set = tree<A, null_type, B, rb_tree_tag, tree_order_statistics_node_update>;
template <typename A, typename B, typename C = less<A>> using ordered_map = tree<A, B, C, rb_tree_tag, tree_order_statistics_node_update>;

void prep();
void solve(const int curt);

const int dx4[4] = {0, 0, 1, -1}, dy4[4] = {1, -1, 0, 0};
const int dx8[8] = {0, 0, 1, 1, 1, -1, -1, -1}, dy8[8] = {1, -1, 1, 0, -1, 1, 0, -1};
const bool isT = true;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	prep();

	int t = 1; if(isT)cin >> t;
	for(int i = 1; i <= t; ++i)solve(i);
}


template <typename A> constexpr A phi(A x) noexcept{
	A res = x;
	if(~x&1){
		while(~x&1){
			x>>=1;
		}
		res >>= 1;
	}
	for(A p = static_cast<A>(3); p * p <= x; p += 2){
		if(!(x % p)) {
			while(!(x % p)) {
				x /= p;
			}
			res -= res / p;
		}
	}
	if(x > static_cast<A>(1)){
		return res - res / x;
	}
	return res;
}


template <int MOD> struct FastMod{
	static constexpr const __uint128_t m = ~1ULL / MOD;
	ll reduce(long long a) { 
		if(a < MOD && a >= 0)return a;
		a = a - static_cast <unsigned long long> ((__uint128_t(m) * a) >> 64) * MOD;
		a += MOD * (a < 0);
		a -= MOD * (a >= MOD);
		return a;
		//return a % b;
	}
};


//FastMod <1000000007> mod;
FastMod <998244353> mod;

constexpr const bool pri_mod = true;

template<template <int> typename T, int N>
constexpr int extr(const T<N>&) { return N; }

constexpr const int phi_mod_val = pri_mod ? extr(mod) - 1 : phi(extr(mod));
FastMod <phi_mod_val> phi_mod;

template <typename A> A inverse(A a, A b) {
	a %= b;
	if(!a) {
		return b == 1 ? 0 : -1;
	}
	int c = inverse(b,a);
	return c == -1 ? -1 : ((1LL - static_cast<long long>(b) * static_cast<long long>(c)) / static_cast<long long>(a)) % b;
}

struct Mint {
	long long val;
	explicit operator int() const { return val; }
	Mint(long long _val = 0) : val(mod.reduce(_val)) {}
	template <typename B = int> Mint(const B& _val) : val(mod.reduce(static_cast<long long>(_val))) {}
	friend bool operator == (const Mint &a, const Mint &b) { return a.val == b.val; }
	friend bool operator != (const Mint &a, const Mint &b) { return !(a == b); }
	friend bool operator < (const Mint &a, const Mint &b) { return a.val < b.val; }
	Mint operator -() const { return Mint(-val); }
	Mint &operator += (const Mint &o) {
		val += o.val;
		if(val >= extr(mod))val -= extr(mod);
		return *this;
	}
	Mint &operator -= (const Mint &o) {
		val -= o.val;
		if(val < 0)val += extr(mod);
		return *this;
	}
	Mint &operator *= (const Mint &o) {
		val = mod.reduce(val * o.val);
		return *this;
	}
	friend Mint pow(Mint a, long long p) {
		p = phi_mod.reduce(p);
		Mint ret = 1;
		while(p) {
			if(p & 1)ret *= a;
			p >>= 1;
			a *= a;
		}
		return ret;
	}
	friend Mint inv(const Mint& a) {
		if constexpr(pri_mod) return pow(a, extr(mod) - 2);
		return inverse(static_cast<int>(a.val), extr(mod));
	}
	Mint &operator /= (const Mint &o) {
		(*this) *= inv(o);
		return *this;
	}
	Mint& operator ++ () {
		return *this += 1;
	}
	Mint& operator -- () {
		return *this -= 1;
	}
	friend Mint operator + (Mint a, const Mint& b) {
		return a += b;
	}
	friend Mint operator - (Mint a, const Mint& b) {
		return a -= b;
	}
	friend Mint operator * (Mint a, const Mint& b) {
		return a *= b;
	}
	friend Mint operator / (Mint a, const Mint& b) {
		return a /= b;
	}
	friend istream& operator >> (istream& s, Mint& a) {
		long long value;
		s >> value;
		a.val = mod.reduce(value);
		return s;
	}
	friend ostream& operator << (ostream& s, const Mint& a) {
		s << a.val;
		return s;
	}
};


void prep(){

}

void solve(const int curt){
	ll n; cin >> n;
	vector<int> v(n);
	for(auto &x : v)cin >> x;
	vector<int> v2 = v;
	sort(v2.begin(),v2.end());
	int dif = 0;
	for(int i = 0; i < n; ++i)dif+=v2[i]^v[i];
	dif >>= 1;

	Mint ans = 0;
	Mint choice = (n * (n-1))/2;
	ll top = 0;
	for(ll i = 1; i <= dif; ++i){
		ans += choice/(i * i);
	}	
	cout << ans << '\n';
}