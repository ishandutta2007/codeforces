#include <bits/stdc++.h>
using namespace std;
#define ep 1e-9
#define M 1111111
#define INF 1e18
const int mod = 1e9 + 7;
typedef long long LL;

double x[M], y[M];
inline bool same(double x, double y) {return fabs(x - y) < ep;}
struct dat {
	double x, y, z;
	dat (double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
	bool operator < (const dat &a) const {
		return same(x, a.x) ? same(y, a.y) ? z < a.z : y < a.y : x < a.x;
	}
} p[M];
int n, m, A, B, C, D;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
  	scanf("%d %d %d %d", &A, &B, &C, &D);
		x[i] = 1. * A * B * D * D / (A * A * D * D + B * B * C * C);
		y[i] = 1. * B * B * C * D / (A * A * D * D + B * B * C * C);
  }
  for (int i = 0; i < n; i++) {
  	for (int j = i + 1; j < n; j++)
			p[m++] = dat(x[i] + x[j], y[i] + y[j], same(y[i], y[j]) ? INF : (x[i] - x[j]) / (y[i] - y[j]));
  }
  sort(p, p + m);
  int l = 0, r;
  LL ans = 0;
  for ( ; l < m; ) {
		for (r = l; r < m && same(p[l].x, p[r].x) && same(p[l].y, p[r].y); r++);
    LL tp = 1, c = 1;
    for (int i = l; i < r; i++) {
    	if (i + 1 < r && same(p[i].z, p[i+1].z)) c++;
			else tp = tp * (c + 1) % mod, c = 1;
    }
    ans = (ans + tp - (r - l + 1)) % mod;
    l = r;
  }
  printf("%d\n", (int)(ans + mod) % mod);
}