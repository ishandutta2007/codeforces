#include<bits/stdc++.h>
#define int __int128
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e4 + 5;
int n, m, k, _a[N];

int gcd(int x, int y) { return y? gcd(y, x % y) : x; }
int lcm(int x, int y) { return x / gcd(x, y) * y; }

int mul(int x, int y, int P) {
    int temp=(x*y-(int)((long double)x/P*y+0.5)*P);
    return temp>0?temp:temp+P;
}

int exgcd(int a, int b, int &x, int &y) {
	if(!b) { x = 1, y = 0; return a; }
	int gcd = exgcd(b, a % b, x, y);
	int t = x - (a / b) * y;
	x = y, y = t;
	return gcd;
}

signed main() {
	n = get(), m = get(), k = get();
	int lm = 1;
	for(int i = 1; i <= k; i++) _a[i] = get(), lm = lcm(lm, _a[i]);
	if(lm > n) return cout << "NO" << endl, 0;
	int M = _a[1], X = 0;
	for(int i = 2; i <= k; i++) {
		int m = _a[i], a = (1 - i + _a[i]) % _a[i], x = 0, y = 0;
		int d = exgcd(M, m, x, y);
		int lcm = M / d * m;
		__int128 tmpk = (__int128)x * (a - X) / d;
		int k = tmpk;
		int nx = ((mul(k, M, lcm) + X) % lcm + lcm) % lcm;
		X = nx;
		M = M * m / d;
	}
	if(X == 0) X = M;
	if(X > m - k + 1) return cout << "NO" << endl, 0;
	for(int i = 1; i <= k; i++) 
		if(gcd(lm, X + i - 1) != _a[i]) return cout << "NO" << endl, 0;
	cout << "YES" << endl;
	return 0;
}

//