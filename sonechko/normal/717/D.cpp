#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
ll MOD = 10007;
const ld E = 1e-9;
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
//#define DEBUG
#endif

const int SIZE = 128;

struct matrix{
	ld **a;
	matrix(){
		a = new ld*[1];
		for(int i = 0; i < 1; i++){
			a[i] = new ld[SIZE];
			for(int j = 0; j < SIZE; j++)
				a[i][j] = 0;
		}
	}
};

matrix operator*(matrix a, matrix b){
	matrix ans;
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			ans.a[0][i ^ j] += a.a[0][i] * b.a[0][j];
		}
	}
	return ans;
}

matrix _pow(matrix b, int p){
	if(p == 1)
		return b;
	if(p & 1)
		return b * _pow(b, p - 1);
	matrix res = _pow(b, p >> 1);
	res = res * res;
	return res;
}

int main() {
	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	int k, n;
	cin >> k >> n;
	matrix a;
	a.a[0][0] = 1;
	matrix b;
	for(int i = 0; i <= n; i++){
		cin >> b.a[0][i];
	}
	b = _pow(b, k);
	a = a * b;
	cout << 1 - a.a[0][0] << endl;

}