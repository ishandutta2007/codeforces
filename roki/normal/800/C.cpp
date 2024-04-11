#include <bits/stdc++.h>
                                                   
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i < int(n); i++)
#define nfor(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forr(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define forft(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ms(a, v) memset(a, v, sizeof(a))
#define x first
#define y second
#define X first
#define Y second
#define ft first
#define sc second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

int n, m;
const int N = 200 * 1000 + 5;
bool ban[N];

inline bool read() {
	cin >> n >> m;
	forn (i, n) {
		int x;
		cin >> x;
		ban[x] = true;
	}
	return true;
}

int cnt[N];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

vector<int> primes;

int dp[N];

int calc(int i) {
	if (dp[i] != -1)
		return dp[i];
	dp[i] = cnt[i];
	for (int p : primes) {
		li nt = li(i) * p;
		if (nt < m && gcd((int)nt, m) == nt)
			dp[i] = max(dp[i], cnt[i] + calc((int)nt));
	}
	return dp[i];
}

vector<int> ans;
li mul = 1;

int euler[N];

int bp(int a, int b, int m) {
	li res = 1;
	for (int i = 0; (1 << i) <= b; ++i) {
		if (b & (1 << i))
			res = res * a % m;
		a = (int)(li(a) * a % m);
	}
	return (int)res;
}

int f(int y) {
	int mm = m;
	int g = gcd((int)mul, mm);
	assert(y % g == 0);
	y /= g, mm /= g;
	int a = (int)mul / g;
	return (int)(bp(a, euler[mm] - 1, mm) * li(y) % m);
}

int phi (int n) {
	int result = n;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}

void restore(int i) {
	for (int j = 1; j < m; ++j) {
		if (ban[j])
			continue;
		if (gcd(j, m) == i) {
			if (sz(ans) == 0)
				ans.pb(j), mul = mul * j % m;
			else {
				ans.pb(f(j));
				mul = mul * ans.back() % m;
				assert(mul == j);
			}
					
		}
	}
	if (dp[i] == cnt[i]) {
		return;
	}
	for (int p : primes) {
		li nt = li(i) * p;
		if (nt < m && gcd((int)nt, m) == nt) {
			if (dp[i] == cnt[i] + calc((int)nt)) {
				return restore((int)nt);
			}
		}
	}
	
}

inline void solve() {
	{
		forn (i, N)
			euler[i] = phi(i);
			
		li mm = m;
		for (li i = 2; i * i <= mm; ++i) {
			if (mm % i == 0) {
				primes.pb((int)i);
				while(mm % i == 0) {
					mm /= i;
				}
			}
		}
		if (mm > 1) 
			primes.pb((int)mm);
	}	

	for (int i = 1; i < m; ++i) {
		if (ban[i])
			continue;
		cnt[gcd(m, i)]++;
	}
	
	memset(dp, -1, sizeof dp);
	
	calc(1);
	
	restore(1);
	
	if (!ban[0])
		ans.pb(0);
	cout << sz(ans) << endl;
	for (int x : ans)
		cout << x << ' ';
}

int main() {
#ifdef SU2_PROJ
	assert(freopen("input.txt", "rt", stdin));
	assert(freopen("output.txt", "wt", stdout));
#endif

	srand(time(NULL));

	cout << setprecision(10) << fixed;
	cerr << setprecision(5) << fixed;

	read();
	solve();

#ifdef SU2_PROJ
	cerr << "Time: " << clock() << endl;
#endif
	
	return 0;
}