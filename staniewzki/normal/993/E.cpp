#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;
 
ostream& operator<<(ostream &out, string str) {
	for(char c : str) out << c;
	return out;
}
 
template<class L, class R> ostream& operator<<(ostream &out, pair<L, R> p) {
	return out << "(" << p.first << ", " << p.second << ")";
}
 
template<class T> auto operator<<(ostream &out, T a) -> decltype(a.begin(), out) {
	out << "{";
	for(auto it = a.begin(); it != a.end(); it = next(it))
		out << (it != a.begin() ? ", " : "") << *it;
	return out << "}";
}
 
void dump() { cerr << "\n"; }
template<class T, class... Ts> void dump(T a, Ts... x) {
	cerr << a << ", ";
	dump(x...);
}
 
#ifdef DEBUG
#  define debug(...) cerr << "[" #__VA_ARGS__ "]: ", dump(__VA_ARGS__)
#else
#  define debug(...) false
#endif

#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ST first
#define ND second
 
template<class T> int size(T && a) { return a.size(); }
template<class T> int sz(T && a) { return a.size(); }
 
using LL = long long;
using PII = pair<int, int>;

typedef complex<double> C;
typedef vector<double> vd;
#define all(x) x.begin(), x.end()
void fft(vector<C>& a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, (long double) M_PI / k); // M_PI, lower-case L
		FOR(i,k,2*k-1) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vector<int> rev(n);
	REP(i, n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	REP(i, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) REP(j,k) {
			// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}
vd conv(const vd& a, const vd& b) {
	if (a.empty() || b.empty()) return {};
	vd res(sz(a) + sz(b) - 1);
	int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
	vector<C> in(n), out(n);
	copy(all(a), begin(in));
	REP(i,size(b)) in[i].imag(b[i]);
	fft(in);
	for(auto &x : in) x *= x;
	REP(i,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
	REP(i,sz(res)) res[i] = imag(out[i]) / (4 * n);
	return res;
}

vd xdd(vector<int> &a) {
	vd ret;
	for(int x : a) ret.emplace_back(x);
	return ret;
}

vector<LL> mul(vector<int> &a, vector<int> &b) {
	auto get = conv(xdd(a), xdd(b));
	vector<LL> ret;
	for(auto &x : get) ret.emplace_back(round(x));
	return ret;
}

vector<LL> ans;
vector<int> a;

void solve(int l, int r) {
	debug(l, r);
	if(l > r) return;
	if(l == r) {
		ans[a[l]]++;
		return;
	}

	int m = (l + r) / 2;
	int q = m - l + 2;
	vector<int> x(q), y(q);
	int cnt = 0;
	for(int i = m; i >= l; i--) {
		cnt += a[i];
		x[cnt]++;
	}
	cnt = 0;
	FOR(i, m + 1, r)
		cnt += a[i], y[cnt]++;

	auto to_add = mul(x, y);
	debug(m, x, y, to_add);
	REP(i, size(to_add))
		ans[i] += to_add[i];

	solve(l, m);
	solve(m + 1, r);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	cin >> n >> x;
	a.resize(n), ans.resize(n + 10);
	REP(i, n) {
		cin >> a[i];
		if(a[i] < x) a[i] = 1;
		else a[i] = 0;
	}

	debug(a);

	solve(0, n - 1);
	REP(i, n + 1)
		cout << ans[i] << " ";
	cout << "\n";
}