#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e6 + 3;
const ld E = 1e-10;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".DAT"); _write(x ".SOL")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
#define y1 hello_world
unsigned char ccc;
bool _minus = false;
template<typename T>
inline T sqr(T t) {
	return (t * t);
}
inline void read(ll &n) {
	n = 0;
	_minus = false;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n')
			break;
		if (ccc == '-') {
			_minus = true;
			continue;
		}
		n = n * 10 + ccc - '0';
	}
	if (_minus)
		n *= -1;
}
inline void read(int &n) {
	n = 0;
	_minus = false;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n')
			break;
		if (ccc == '-') {
			_minus = true;
			continue;
		}
		n = n * 10 + ccc - '0';
	}
	if (_minus)
		n *= -1;
}
char wwww[12];
int kkkk;
inline void write(ll y) {
	long long x = y;
	kkkk = 0;
	if (!x)
		++kkkk, wwww[kkkk] = '0';
	else
		while (x) {
			++kkkk;
			wwww[kkkk] = char(x % 10 + '0');
			x /= 10;
		}
	for (int i = kkkk; i >= 1; --i)
		putchar(wwww[i]);
	putchar(' ');
}

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

ll solve_long(int n, int m){
	ll dp[m + 1][n + 1];
	ms(dp);
	dp[0][0] = 1;
	for(int i = 1; i <= m; i++){
		for(int j = 0; j <= n; j++){
			for(int z = 0; z <= j; z++){
				dp[i][j] += dp[i - 1][z];
			}
			dp[i][j] %= MOD;
			//cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++)
		ans += dp[m][i];
	return ans % MOD;
}

ll get_fac(ll n){
	ll ans = 1;
	for(ll i = 2; i <= n; i++){
		ans = (ans * i) % MOD;
	}
	return ans;
}

ll _pow(ll n, ll m){
	return (m == 0 ? 1 : m & 1 ? n * _pow(n, m - 1) : sqr(_pow(n, m >> 1))) % MOD;
}

ll anti_fac(ll n){
	return _pow(get_fac(n), MOD - 2);
}

ll get_c(ll n, ll m){
	ll ans = get_fac(n);
	ans = (ans * anti_fac(m)) % MOD;
	ans = (ans * anti_fac(n - m)) % MOD;
	return ans;
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(5);
	cout << fixed;

#ifdef LOCAL
	input;
#else

#endif

	int n, m;
	cin >> n >> m;

	ll ans = get_c(n + m, m);
	ans--;
	if(ans < 0)
		ans += MOD;

	cout << ans << endl;

}