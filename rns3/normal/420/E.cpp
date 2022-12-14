#include <bits/stdc++.h>
using namespace std;
#define ep 1e-9
#define M 2000010
const double pi = acos(-1);
pair <double, int> p[M];
int m;

void ins(double l, double r) {
  if (r > pi + ep) {
  	ins(l, pi), ins(-pi, r - 2 * pi);
  }
  else if (l < -pi - ep) {
  	ins(-pi, r), ins(l + 2 * pi, pi);
  }
  else {
  	p[m++] = make_pair(l - ep, -1), p[m++] = make_pair(r + ep, 1);
  }
}

int main() {
	//freopen("E.in", "r", stdin);
	int n, d, x, y, r;
	scanf("%d %d", &n, &d);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &x, &y, &r);
		double L = sqrt(x * x + y * y);
		double ang = atan2(y, x);
		for (int j = ceil((L - r) / d - ep); j <= floor((L + r) / d + ep); j++) {
      double R = 1. * j * d;
      double del = acos((R * R + L * L - r * r) / 2 / R / L);
      double al = ang - del, be = ang + del;
      ins(al, be);
		}
	}
	sort(p, p + m);
	int ans(0), tmp(0);
	for (int i = 0; i < m; i++) {
		tmp -= p[i].second;
		if (tmp > ans) ans = tmp;
	}
	printf("%d\n", ans);
}