#include <bits/stdc++.h>
using namespace std;


const double INF = 1e9 * 1.0 * 1e5;
const double ep = 1e-7;

#define N 1010

int n, m, a[N], x[N];
double f[N];

bool ok(double h) {
	for (int i = 1; i <= n; i ++) {
		f[i] = INF;
		for (int j = 0; j < i; j ++) {
            f[i] = min(f[i], f[j] + sqrt(fabs(x[i] - x[j] - m)) - h * a[i]);
		}
	}
	return f[n] > 0;
}

int prv[N];

stack<int> stk;

void solve(double h) {
	for (int i = 1, k; i <= n; i ++) {
		f[i] = INF;
		for (int j = 0; j < i; j ++) if (f[i] > f[j] + sqrt(fabs(x[i] - x[j] - m)) - h * a[i]) f[i] = f[j] + sqrt(fabs(x[i] - x[j] - m)) - h * a[i], k = j;
		prv[i] = k;
	}
    for (int i = n; i; i = prv[i]) stk.push(i);
    while (!stk.empty()) {
		printf("%d ", stk.top());
		stk.pop();
    }
}


int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%d %d", &x[i], &a[i]);
	double mid, st = 0, en = 1e9;
	while (st < en - ep) {
        mid = (st + en) / 2;
		if (ok(mid)) st = mid;
		else en = mid;
	}
	solve(st);
	return 0;
}