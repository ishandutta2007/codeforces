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

using LL = long long;
using PII = pair<int, int>;

int mod = 1e9 + 7;
int add(int a, int b) {
	return a + b < mod ? a + b : a + b - mod;
}

int mul(int a, int b) {
	return (LL) a * b % mod;
}

using Matrix = vector<vector<int>>;
Matrix mul(Matrix a, Matrix b) {
	Matrix ret = a;
	int A = size(a);
	REP(i, A) REP(j, A) {
		ret[i][j] = 0;
		REP(k, A) ret[i][j] = add(ret[i][j], mul(a[i][k], b[k][j]));
	}
	return ret;
}

int identity(int a) { return 1; }
Matrix identity(Matrix a) {
	int s = size(a);
	Matrix ret(s, vector<int>(s));
	REP(i, s) ret[i][i] = 1;
	return ret;
}

template<class T> 
T qpow(T a, int n) {
	if(n == 0) return identity(a);
	if(n % 2 == 1) return mul(qpow(a, n - 1), a);
	return qpow(mul(a, a), n / 2);
}

Matrix construct(int n, int z) {
	int all = n * (n - 1) / 2;
	int rev = qpow(all, mod - 2);
	Matrix ret(z + 1, vector<int>(z + 1));
	REP(i, z + 1) {
		int res = all;
		if(i != 0) {
			ret[i][i - 1] = mul(i, n - 2 * z + i);
			res -= ret[i][i - 1];
			ret[i][i - 1] = mul(ret[i][i - 1], rev);
		}
		if(i != z) {
			ret[i][i + 1] = mul(z - i, z - i);
			res -= ret[i][i + 1];
			ret[i][i + 1] = mul(ret[i][i + 1], rev);
		}
		ret[i][i] = mul(res, rev);
	}


	// zera na lewo: i
	// jedynki na lewo: z - i
	// zera na prawo: z - i
	// jedynki na prawo: n - 2 * z + 1
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	array<int, 2> cnt = {0, 0};
	REP(i, n) {
		cin >> a[i];
		cnt[a[i]]++;
	}

	auto m = construct(n, cnt[0]);
	auto g = qpow(m, k);		

	REP(i, size(m))
		debug(i, m[i]);

	int z = 0;
	REP(i, cnt[0]) if(not a[i]) z++;
	cout << g[z][cnt[0]] << "\n";
}