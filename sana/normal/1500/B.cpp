#if 1
#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

#include <bits/stdc++.h>
using namespace std;

#if 0
    #include <bits/extc++.h>
    using namespace __gnu_pbds;

    template<class T>
    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;
#endif

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

typedef string str;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());

#define ts to_string
str ts(char c) { return str(1,c); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
template<class A> str ts(complex<A> c) { stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) { str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) { str res = ""; F0R(i,SZ) res += char('0'+b[i]); return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { bool fst = 1; str res = "{"; for (const auto& x: v) {if (!fst) res += ", ";	fst = 0; res += ts(x);}	res += "}"; return res;}
template<class A, class B> str ts(pair<A,B> p) {return "("+ts(p.first)+", "+ts(p.second)+")"; }
 
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { pr(h); pr(t...); }
void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {cerr << ts(h); if (sizeof...(t)) cerr << ", ";	DBG(t...); }

int myrand(int l, int r) { return uniform_int_distribution(l, r)(rng); }

#endif

template <typename T>
T gcd(T a, T b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

template <typename T>
T extGcd(T a, T b, T& x, T& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	else {
		int g = extGcd(b, a % b, y, x);
		y -= a / b * x;
		return g;
	}
}

template <typename T>
T modInv(T a, T m) {
	T x, y;
	extGcd(a, m, x, y);
	return (x % m + m) % m;
}

long long crt(const std::vector< std::pair<int, int> >& a, int mod) {
	long long res = 0;
	long long mult = 1;

	int SZ = a.size();
	std::vector<int> x(SZ);
	for (int i = 0; i<SZ; ++i) {
		x[i] = a[i].first;
		for (int j = 0; j<i; ++j) {
			long long cur = (x[i] - x[j]) * 1ll * modInv(a[j].second,a[i].second);
			x[i] = (int)(cur % a[i].second);
			if (x[i] < 0) x[i] += a[i].second;
		}
		res = (res + mult * 1ll * x[i]);
		mult = (mult * 1ll * a[i].second);
		if (mod != -1) {
			res %= mod;
			mult %= mod;
		}
	}

	return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m; long long k;
    cin >> n >> m >> k;

    vi a(n), b(m);
    vi locA(2*max(n,m), -1), locB(2*max(n,m), -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        locA[a[i]] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        b[i]--;
        locB[b[i]] = i;
    }

    int g = gcd(n,m);
    vector< long long > matches;

    long long cyc = n * 1ll * m / g;
    for (int i = 0; i < 2*max(n,m); i++) {
        if (locA[i] != -1 && locB[i] != -1) {
            if (locA[i] % g == locB[i] % g) {
                long long res = crt(vector<pii>{ {locA[i] / g, n / g}, {locB[i] / g, m / g} }, -1);
                matches.push_back(res * 1ll * g + locA[i] % g);
            }
        }
    }

    sort(all(matches));

    long long full_cycles = (k-1) / (cyc - sz(matches));
    k -= full_cycles * 1ll * (cyc - sz(matches));
    long long at = full_cycles * cyc;

    matches.push_back(cyc);
    long long la = -1;

    for (long long x : matches) {
        if (x - la - 1 >= k) {
            cout << at + k << endl;
            return 0;
        } 
        
        k -= (x - la - 1);
        at += (x - la);
        la = x;
    }

    return 0;
}