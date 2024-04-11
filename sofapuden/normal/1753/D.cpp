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
const bool isT = false;

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


FastMod <1000000007> mod;
//FastMod <998244353> mod;

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


namespace dbg {

	string to_string(const string s);
	string to_string(const char* c);
	string to_string(const bool& b);
	string to_string(const char& c);
	template<typename A> string to_string(A x);
	template<typename A> string to_string(const vector<A> &V);
	template<typename A> string to_string(const stack<A> &S);
	template<typename A> string to_string(const deque<A> &V);
	template<typename A> string to_string(const set<A> &S);
	template<typename A> string to_string(const unordered_set<A> &S);
	template<typename A> string to_string(const queue<A> &Q);
	template<typename A> string to_string(const std::priority_queue<A> &Q);
	template<typename A, size_t sz > string to_string(const array<A, sz> &V);
	template<typename A, typename B> string to_string(const pair<A, B> &p);
	template<typename A, typename B> string to_string(const set<A, B> &S);
	template<typename A, typename B> string to_string(const unordered_set<A, B> &S);
	template<typename A, typename B> string to_string(const map<A, B> &M);
	template<typename A, typename B> string to_string(const unordered_map<A, B> &M);
	template<typename A, typename B> string to_string(const queue<A, B> &Q);
	template<typename A, typename B> string to_string(const std::priority_queue<A, B> &Q);
	template<typename A, typename B> string to_string(tree<A, null_type, B, rb_tree_tag, tree_order_statistics_node_update> &T);
	template<typename A, typename B, typename C> string to_string(const set<A, B, C> &S);
	template<typename A, typename B, typename C> string to_string(const unordered_set<A, B, C> &S);
	template<typename A, typename B, typename C> string to_string(const map<A, B, C> &M);
	template<typename A, typename B, typename C> string to_string(const unordered_map<A, B, C> &M);
	template<typename A, typename B, typename C> string to_string(const std::priority_queue<A, B, C> &Q);
	template<typename A, typename B, typename C> string to_string(tree<A, B, C, rb_tree_tag, tree_order_statistics_node_update> &T);

	string to_string(const string s) {
		return '"' + s + '"';
	}

	string to_string(const char* s) {
		return to_string((string)s);
	}

	string to_string(const bool& b) {
		return b ? "True" : "False";
	}

	string to_string(const char& c) {
		return (string)"'" + c + "'";
	}

	template<typename A> string to_string(A x) {
		stringstream s;
		s << fixed << setprecision(4) << x;
		return s.str();
	}

	template<typename A> string to_string(const vector<A> &V) {
		if(V.empty()){
			return "{ }";
		}
		string ret = "{";
		for(auto it = V.begin(); it != V.end(); ++it){
			ret += to_string(*it) + (next(it) == V.end() ? "}" : ", ");
		}
		return ret;
	}

	template<typename A> string to_string(const stack<A> &S) {
		if(S.empty()){
			return "{ }";
		}
		string ret = "{";
		for(auto it = S.begin(); it != S.end(); ++it){
			ret += to_string(*it) + (next(it) == S.end() ? "}" : ", ");
		}
		return ret;

	}

	template<typename A> string to_string(const deque<A> &V){
		if(V.empty()){
			return "{ }";
		}
		string ret = "{";
		for(auto it = V.begin(); it != V.end(); ++it){
			ret += to_string(*it) + (next(it) == V.end() ? "}" : ", ");
		}
		return ret;
	}

	template<typename A> string to_string(const set<A> &S){
		if(S.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = S.begin(); it != S.end(); ++it){
			ret += to_string(*it) + (next(it) == S.end() ? "]" : ", ");
		}
		return ret;
	}

	template<typename A> string to_string(const unordered_set<A> &S){
		if(S.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = S.begin(); it != S.end(); ++it){
			ret += to_string(*it) + (next(it) == S.end() ? "]" : ", ");
		}
		return ret;
	}

	template<typename A> string to_string(const queue<A> &Q){
		if(Q.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = Q.begin(); it != Q.end(); ++it){
			ret += to_string(*it) + (next(it) == Q.end() ? "]" : ", ");
		}
		return ret;
	}

	template<typename A> string to_string(const std::priority_queue<A> &Q){
		if(Q.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = Q.begin(); it != Q.end(); ++it){
			ret += to_string(*it) + (next(it) == Q.end() ? "]" : ", ");
		}
		return ret;
	}

	template<typename A, size_t sz>  string to_string(const array<A, sz> &V){
		if(V.empty()){
			return "{ }";
		}
		string ret = "{";
		for(size_t i = 0; i < sz; ++i){
			ret += to_string(V[i]) + (i + size_t(1) == sz ? "}" : ", ");
		}
		return ret;
	}

	template<typename A, typename B> string to_string(const pair<A, B> &p){
		return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
	}

	template<typename A, typename B> string to_string(const set<A, B> &S){
		if(S.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = S.begin(); it != S.end(); ++it){
			ret += to_string(*it) + (next(it) == S.end() ? "]" : ", ");
		}
		return ret;
	}

	template<typename A, typename B> string to_string(const unordered_set<A, B> &S){
		if(S.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = S.begin(); it != S.end(); ++it){
			ret += to_string(*it) + (next(it) == S.end() ? "]" : ", ");
		}
		return ret;
	}

	template<typename A, typename B> string to_string(const map<A, B> &M){
		if(M.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = M.begin(); it != M.end(); ++it){
			ret += "(" + to_string(it->first) + ": " + to_string(it->second) + (next(it) == M.end() ? ")]" : "), ");
		}
		return ret;
	}

	template<typename A, typename B> string to_string(const unordered_map<A, B> &M){
		if(M.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = M.begin(); it != M.end(); ++it){
			ret += "(" + to_string(it->first) + ": " + to_string(it->second) + (next(it) == M.end() ? ")]" : "), ");
		}
		return ret;
	}

	template<typename A, typename B> string to_string(const queue<A, B> &Q){
		if(Q.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = Q.begin(); it != Q.end(); ++it){
			ret += to_string(*it) + (next(it) == Q.end() ? "]" : ", ");
		}
		return ret;
	}

	template<typename A, typename B> string to_string(const std::priority_queue<A, B> &Q){
		if(Q.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = Q.begin(); it != Q.end(); ++it){
			ret += to_string(*it) + (next(it) == Q.end() ? "]" : ", ");
		}
		return ret;
	}

	template<typename A, typename B> string to_string(tree<A, null_type, B, rb_tree_tag, tree_order_statistics_node_update> &S){
		if(S.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = S.begin(); it != S.end(); ++it){
			ret += to_string(*it) + (next(it) == S.end() ? "]" : ", ");
		}
		return ret;
	}

	template<typename A, typename B, typename C> string to_string(const set<A, B, C> &S){
		if(S.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = S.begin(); it != S.end(); ++it){
			ret += to_string(*it) + (next(it) == S.end() ? "]" : ", ");
		}
		return ret;
	}

	template<typename A, typename B, typename C> string to_string(const unordered_set<A, B, C> &S){
		if(S.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = S.begin(); it != S.end(); ++it){
			ret += to_string(*it) + (next(it) == S.end() ? "]" : ", ");
		}
		return ret;
	}

	template<typename A, typename B, typename C> string to_string(const map<A, B, C> &M){
		if(M.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = M.begin(); it != M.end(); ++it){
			ret += "(" + to_string(it->first) + ": " + to_string(it->second) + (next(it) == M.end() ? ")]" : "), ");
		}
		return ret;
	}

	template<typename A, typename B, typename C> string to_string(const unordered_map<A, B, C> &M){
		if(M.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = M.begin(); it != M.end(); ++it){
			ret += "(" + to_string(it->first) + ": " + to_string(it->second) + (next(it) == M.end() ? ")]" : "), ");
		}
		return ret;
	}

	template<typename A, typename B, typename C> string to_string(const std::priority_queue<A, B, C> &Q){
		if(Q.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = Q.begin(); it != Q.end(); ++it){
			ret += to_string(*it) + (next(it) == Q.end() ? "]" : ", ");
		}
		return ret;
	}
	template<typename A, typename B, typename C> string to_string(tree<A, B, C, rb_tree_tag, tree_order_statistics_node_update> &M){
		if(M.empty()){
			return "[ ]";
		}
		string ret = "[";
		for(auto it = M.begin(); it != M.end(); ++it){
			ret += "(" + to_string(it->first) + ": " + to_string(it->second) + (next(it) == M.end() ? ")]" : "), ");
		}
		return ret;
	}

	void dbg_out() {
		cerr << endl;
	}

	template<typename A, typename... B> void dbg_out(A a, B... b){
		std::cerr << "\033[96m " << to_string(a) << "\033[0m";
		dbg_out(b...);
	}

	void dbm_tab(const int cnt = 1) {
		cerr << string(cnt,' ');
	}

	template<typename A> void dbm_out(A a){
		for(auto it = a.begin(); it != a.end(); ++it){
			dbm_tab(1);
			std::cerr << "\033[96m[ " << to_string(*it) << " ]\033[0m" << endl;
		}
	}
}

#ifndef ONLINE_JUDGE
#define debug(...) std::cerr << "\033[94m[" << #__VA_ARGS__ << "]:\033[0m", dbg::dbg_out(__VA_ARGS__)
#define debum(...) std::cerr << "\033[94m[" << #__VA_ARGS__ << "]:\033[0m\n", dbg::dbm_out(__VA_ARGS__)
#else
#define debug(...)
#define debum(...)
#endif


void prep(){

}
const ll MX = (1ll<<60);
int N, M;

bool inside(int x, int y){
	if(x < 0 || x >= N || y < 0 || y >= M)return false;
	return true;
}

void solve(const int curt){
	int n, m; cin >> n >> m;
	N = n, M = m;
	ll p, q; cin >> p >> q;
	vector<vector<ll>> vis(n,vector<ll>(m,-1));
	vector<string> gr(n);
	for(auto &x : gr)cin >> x;
	std::priority_queue<array<ll,3>> pq;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(gr[i][j] == '.')pq.push({0,i,j});
		}
	}
	ll ans = MX;
	while(pq.size()){
		auto val = pq.top()[0];
		auto x = pq.top()[1];
		auto y = pq.top()[2];
		pq.pop();
		if(vis[x][y] != -1)continue;
		vis[x][y] = -val;
		for(int i = 0; i < 4; ++i){
			auto nx = x + dx4[i];
			auto ny = y + dy4[i];
			if(!inside(nx,ny))continue;
			if(gr[nx][ny] == '#')continue;
			if(gr[nx][ny] == '.')ans = min(ans,-val);
			if(gr[nx][ny] == 'U'){
				ll mn = 0;
				if(x != nx){
					if((inside(nx+1,ny + 1) && gr[nx+1][ny+1] == '.')||(inside(nx+1, ny-1) && gr[nx+1][ny-1] == '.')){
						mn = min(q,2*p);
					}
					else mn = q;					
				}
				else {
					mn = p;
				}
				pq.push({val-mn,nx+1,ny});
			}
			if(gr[nx][ny] == 'D'){
				ll mn = 0;
				if(x != nx){
					if((inside(nx-1,ny + 1) && gr[nx-1][ny+1] == '.')||(inside(nx-1, ny-1) && gr[nx-1][ny-1] == '.')){
						mn = min(q,2*p);
					}
					else mn = q;					
				}
				else {
					mn = p;
				}
				pq.push({val-mn,nx-1,ny});
			}
			if(gr[nx][ny] == 'L'){
				ll mn = 0;
				if(y != ny){
					if((inside(nx+1,ny + 1) && gr[nx+1][ny+1] == '.')||(inside(nx-1, ny+1) && gr[nx-1][ny+1] == '.')){
						mn = min(q,2*p);
					}
					else mn = q;					
				}
				else {
					mn = p;
				}
				pq.push({val-mn,nx,ny+1});
			}
			if(gr[nx][ny] == 'R'){
				ll mn = 0;
				if(y != ny){
					if((inside(nx+1,ny - 1) && gr[nx+1][ny-1] == '.')||(inside(nx-1, ny-1) && gr[nx-1][ny-1] == '.')){
						mn = min(q,2*p);
					}
					else mn = q;					
				}
				else {
					mn = p;
				}
				pq.push({val-mn,nx,ny-1});
			}
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(vis[i][j] == -1)continue;
			if(i && vis[i-1][j] != -1)ans = min(ans, vis[i][j] + vis[i-1][j]);
			if(j && vis[i][j-1] != -1)ans = min(ans, vis[i][j] + vis[i][j-1]);
		}
	}
	cout << (ans == MX ? -1 : ans) << '\n';
}