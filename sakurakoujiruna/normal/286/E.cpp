#include <bits/stdc++.h>
using namespace std;

using vi = vector <int>;

using ld = double;
using comp = complex<ld>;
using vc = vector<comp>; const ld PI = atan(1.0L) * 4;
void dft(vc &a, int op = 1) {
	int n = a.size();
	for (int i = 1, j = 0; i < n - 1; ++i) {
		for (int s = n; j ^= s >>= 1, ~j & s;) {}
		if (i < j) swap(a[i], a[j]);
	}
	for (int i = 1; i < n; i *= 2) {
		comp u = {cos(PI / i), op * sin(PI / i)};
		for (int j = 0; j < n; j += i * 2) {
			comp w = 1;
			for (int k = 0; k < i; ++k, w = w * u) {
				comp x = a[j + k], y = w * a[j + k + i];
				a[j + k] = x + y, a[j + k + i] = x - y;
	}}}
	if (op == -1) for (int i = 0; i < n; ++i) a[i] /= n;
}
vi multi(vi a, vi b) {
	int n = 1; while (n < a.size() + b.size() - 1) n *= 2;
	vc fa(n), fb(n), fc(n);
	copy(a.begin(), a.end(), fa.begin()); dft(fa);
	copy(b.begin(), b.end(), fb.begin()); dft(fb);
	for (int i = 0; i < n; ++i) fc[i] = fa[i] * fb[i];
	dft(fc, -1); vi c(n);
	for (int i = 0; i < n; ++i) c[i] = round(fc[i].real());
	return c;
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	vi v(m + 1); v[0] = 1;
	for(int i = 0; i < n; i ++) {
		int x; scanf("%d", &x);
		v[x] = 1;
	}
	vi u = multi(v, v), ans;
	for(int i = 1; i <= m; i ++) {
		if(!v[i] && u[i]) {
			puts("NO");
			return 0;
		}
		if(u[i] == 2)
			ans.push_back(i);
	}
	puts("YES");
	printf("%d\n", ans.size());
	for(int x : ans)
		printf("%d ", x);
	puts("");

	return 0;
}