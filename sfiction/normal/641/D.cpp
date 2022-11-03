#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MAXN = 1E5 + 10;

int n;
double a[MAXN], b[MAXN];
double c[MAXN], d[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lf", &a[i]);
	for (int i = 0; i < n; ++i)
		scanf("%lf", &b[i]);
	for (int i = 1; i < n; ++i)
		a[i] += a[i - 1];
	for (int i = n - 2; i >= 0; --i)
		b[i] += b[i + 1];
	double p1 = 1, p2 = 1;
	for (int i = 0; i < n - 1; ++i){
		double p = a[i], q = b[i + 1];
		double r = 1 - q + p;
		double s = sqrt(max(0.0, r * r - 4 * p));
		c[i] = (r + s) / 2;
		d[i] = (r - s) / 2;
	}
	c[n - 1] = d[n - 1] = 1;
	for (int i = n - 1; i > 0; --i)
		c[i] -= c[i - 1], d[i] -= d[i - 1];
	for (int i = 0; i < n; ++i)
		printf("%.8f%c", c[i], "\n "[i + 1 < n]);
	for (int i = 0; i < n; ++i)
		printf("%.8f%c", d[i], "\n "[i + 1 < n]);
	return 0;
}