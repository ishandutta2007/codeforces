#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define LLD "%lld"
#else
#define eprintf(...) 42
#define LLD "%I64d"
#endif
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash

typedef long long ll;
typedef long long llong;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;

const ll inf = ll(1e18);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int delta = 100;

inline int gcd(int a, int b){
	while(b > 0){
		a %= b;
		swap(a, b);
	}
	return a;
}

inline ll sqr(ll a){
	return a * a;
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, x, y, a, b;
	scanf("%d %d %d %d %d %d", &n, &m, &x, &y, &a, &b);
	int g = gcd(a, b);
	a /= g;
	b /= g;
	int k = min(n / a, m / b);
	int w = k * a, h = k * b;
	int cx = max(2 * x - w, 0) / 2, cy = max(2 * y - h, 0) / 2;
	cx = max(cx, x - w);
	cx = min(cx, x);
	cx = min(cx, n - w);
	cy = max(cy, y - h);
	cy = min(cy, y);
	cy = min(cy, m - h);
	ll ans = -1;
	int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
	for(int i = -delta; i <= delta; i++){
		for(int j = -delta; j <= delta; j++){
			int xx = cx + i, yy = cy + j;
			if(xx >= 0 && xx + w <= n && yy >= 0 && yy + h <= m && xx <= x && x <= xx + w && yy <= y && y <= yy + h){
				ll res = sqr(2LL * xx + w - 2LL * x) + sqr(2LL * yy + h - 2LL * y);
				if(ans == -1 || res < ans || (ans == res && xx < x1) || (ans == res && xx == x1 && yy < y1)){
					ans = res;
					x1 = xx;
					y1 = yy;
					x2 = xx + w;
					y2 = yy + h;
				}
			}
		}
	}
	printf("%d %d %d %d\n", x1, y1, x2, y2);
	return 0;
}