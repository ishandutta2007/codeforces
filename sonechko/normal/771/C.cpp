#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
const ld E = 1e-7;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#ifndef LONG_LONG_MAX
#define LONG_LONG_MAX LLONG_MAX
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".dat"); _write(x ".sol")
#define output _write("output.txt")
#define input _read("input.txt")
#define prev time_prev
#define M_PI acos(-1)
#define remove tipa_remove
#define left tipa_left
#define right tipa_right
#define next tipa_next
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
char wwww[19];
int kkkk;
inline void write(ll y) {
	long long x = y;
	kkkk = 0;
	if (x < 0) {
		putchar('-');
		x *= -1;
	}
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
}

#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = 2e5 + 10;

ll dp[MAX][6];
ll dp2[MAX][6];
vector<int> vec[MAX];
int n, k;

ll ans = 0;

void dfs1(int pos, int from = -1) {
	for (int a : vec[pos]) {
		if (a != from) {
			dfs1(a, pos);
			for (int j = 1; j < k; j++) {
				dp[pos][j + 1] += dp[a][j];
			}
			dp[pos][0] += dp[a][0];
			dp[pos][0] += dp[a][k];
			dp[pos][1] += dp[a][k];
			dp[pos][1]++;
			dp[pos][0]++;
		}
	}
	ans += dp[pos][0];
}

void dfs2(int pos, int from = -1) {
	for (int a : vec[pos]) {
		if (a != from) {
			for (int j = 1; j < k; j++) {
				dp[pos][j + 1] -= dp[a][j];
			}
			dp[pos][0] -= dp[a][0];
			dp[pos][0] -= dp[a][k];
			dp[pos][1] -= dp[a][k];
			dp[pos][1]--;
			dp[pos][0]--;
			for (int j = 1; j < k; j++) {
				dp2[a][j + 1] += dp[pos][j] + dp2[pos][j];
			}
			dp2[a][0] += dp[pos][0] + dp2[pos][0];
			dp2[a][0] += dp[pos][k] + dp2[pos][k];
			dp2[a][1] += dp[pos][k] + dp2[pos][k];
			dp2[a][1]++;
			dp2[a][0]++;
			dfs2(a, pos);
			for (int j = 1; j < k; j++) {
				dp[pos][j + 1] += dp[a][j];
			}
			dp[pos][0] += dp[a][0];
			dp[pos][0] += dp[a][k];
			dp[pos][1] += dp[a][k];
			dp[pos][1]++;
			dp[pos][0]++;
		}
	}
	ans += dp2[pos][0];
}

int main() {
	sync;
	srand(time(NULL));
	cout.precision(3);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	cin >> n >> k;
	for(int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	int root = 1;

	dfs1(root);
	dfs2(root);

	cout << ans / 2 << endl;

}