#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
#define int ll
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
const ld E = 1e-5;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#ifndef M_PI
#define M_PI 3.141592653589793238462643383
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
char wwww[19];
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

const int MAX = 2e5 + 10;

int dp[MAX];
int has[MAX];

bool used[MAX];
int from[MAX];

vector<int> vec[MAX];

ll _pow(ll a, ll b, ll m){
	return (b == 0 ? 1 : b & 1 ? a * _pow(a, b - 1, m) : sqr(_pow(a, b >> 1, m))) % m;
}
//x * y == z
// a = z
// b = x

//7 * y = 3
//y = 3

int gcd (int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int get(int a, int m){
	int x, y;
	//cout << a << " " << m << endl;
	int g = gcd(a, m, x, y);
	if (g != 1)
		assert(false);
	else {
		x = (x % m + m) % m;
		//cout << "! " << x << endl;
		return x;
	}
}

int solve(int a, int b, int m){
	int B = b;
	int M = m;
	int w = __gcd(B, M);
	int g = get(b / w, m / w);
	assert(a % w == 0);
	g *= a / w;
	g %= m;
	if((b * g) % m != a){
		assert(false);
		cout << "error " << a << " " << b << " " << m << " " << g << endl;
	}
	return g;
}

#undef int
int main() {
#define int ll
	sync;
	srand(time(NULL));
	cout.precision(12);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	int n, m;
	cin >> n >> m;

	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		used[a] = true;
	}

	if(m == 1){
		vector<int> ans;
		for(int i = 0; i >= 0; i--){
			if(!used[i]){
				ans.push_back(i);
			}
		}
		cout << ans.size() << endl;
		for(int a : ans){
			cout << a << " ";
		}
		cout << endl;
		return 0;
	}

	for(int i = 1; i < m; i++) {
		if(!used[i]) {
			has[__gcd(i, m)]++;
			dp[__gcd(i, m)]++;
			vec[__gcd(i, m)].push_back(i);
		}
	}

	int t = m;

	vector<int> q;

	for(int i = 2; i <= t; i++) {
		if(t % i == 0) {
			while(t % i == 0) {
				t /= i;
			}
			q.push_back(i);
		}
	}

	int ans = 0;
	int pos = 0;

	for(int i = 1; i < m; i++) {
		if(dp[i]) {
			for(int a : q){
				if(m % (1LL * a * i) == 0 && dp[i] + has[a * i] > dp[a * i]){
					dp[a * i] = dp[i] + has[a * i];
					from[a * i] = i;
				}
			}
			if(dp[i] > ans){
				ans = dp[i];
				pos = i;
			}
		}
	}

	vector<int> v;

	while(pos){
		for(int a : vec[pos]){
			v.push_back(a);
		}
		pos = from[pos];
	}

	reverse(v.begin(), v.end());

#ifdef LOCAL
	for(int a : v){
		cout << a << " ";
	}
	cout << endl;
#endif

	for(int i = (int) v.size() - 1; i > 0; i--){
		v[i] = solve(v[i], v[i - 1], m);
	}

	if(!used[0]){
		v.push_back(0);
	}

	cout << v.size() << endl;
	for(int a : v){
		cout << a << " ";
	}
	cout << endl;


#ifdef LOCAL
	int s = 1;
	for(int a : v){
		s *= a;
		s %= m;
		cout << s << " ";
	}
	cout << endl;
#endif
	//todo 0
	//todo test m = 2
	//todo test with only one element

}