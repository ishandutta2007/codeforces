#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>

#define y1 ashskjfkjsh_y1

using namespace std;

int gcd(int a, int b) {
	if (!b) return a; 
	return gcd(b, a % b);
}

int n, m, x, y, a, b;
int x1, y1, x2, y2;

int get(const int &pos, const int &dim, const int &len) {
	int l = max(0, pos - len), r = min(pos, dim - len);
	if (l + (len + 1) / 2 >= pos) return l;
	if (r + len / 2 <= pos) return r;
	return max(l, pos - (len + 1) / 2);
}

int main() {
	cin >> n >> m >> x >> y >> a >> b;
	int l = gcd(a, b);
	int p = a / l, q = b / l;
	int max_w = min(n / p, m / q);
	int len_n = max_w * p, len_m = max_w * q;
	x1 = get(x, n, len_n);
	y1 = get(y, m, len_m);
	x2 = x1 + len_n, y2 = y1 + len_m;
	cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;	
	return 0;
}