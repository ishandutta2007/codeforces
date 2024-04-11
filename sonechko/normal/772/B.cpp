#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
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

ld dist(ii a, ii b){
	return (ld) sqrt((ld) sqr(a.first - b.first) + sqr(a.second - b.second));
}

ld s(ii a, ii b, ii c){
	ld ans = 0;
	ans += (a.first - b.first) * (a.second + b.second);
	ans += (b.first - c.first) * (b.second + c.second);
	ans += (c.first - a.first) * (c.second + a.second);
	return abs(ans) / 2;
}

ld solve(ii a, ii b, ii c){
	ld s = ::s(a, b, c);
	ld t = dist(a, b) * dist(b, c) * dist(a, c);
	t /= 4 * s;
	return t;
}

ld solve2(ii a, ii b, ii c){
	ld s = ::s(a, b, c);
	ld w = max(max(dist(a, b), dist(b, c)), dist(a, c));
	ld ans = 2 * s / w;
	return ans;
}

int main() {
	sync;
	srand(time(NULL));
	cout.precision(12);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	vector<ii> vec(n);

	for(int i = 0; i < n; i++){
		cin >> vec[i].first >> vec[i].second;
	}

	ld ans = 1e18;

	for(int i = 0; i < n; i++){
		ii a = vec[i];
		ii b = vec[(i + 1) % n];
		ii c = vec[(i + 2) % n];
		ans = min(ans, solve(a, b, c) / 2);
		ans = min(ans, dist(a, b) / 2);
		ans = min(ans, solve2(a, b, c) / 2);
	}


	cout << ans << endl;

}