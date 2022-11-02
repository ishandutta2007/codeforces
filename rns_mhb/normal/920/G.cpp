#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define f3(i, a, b) for (int i = a; i >= b; i --)

typedef vector <int> vi;

#define N 1000005
#define M 1005

int a[N], p[N], mu[N], ps;
bool ris[N], vis[N];
vi v[N];

int calc(int x, vi &v) {
    int res = 0;
    for (auto y : v) res += mu[y] * (x / y);
    return res;
}

int main() {
	int T;
    mu[1] = 1;
	f0(i, 1, N) a[i] = 1;
	for (int i = 2; i < N; i ++) {
		if (!vis[i]) {
			p[++ps] = i, mu[i] = -1;
            for (int j = i; j < N; j += i) a[j] *= i;
		}
		for (int j = 1; j <= ps && i * p[j] < N; j ++) {
			int k = i * p[j];
			vis[k] = 1;
			if (i % p[j] == 0) break;
			mu[k] = -mu[i];
		}
	}
    int x, p, k;
	for (scanf("%d", &T); T --; ) {
		scanf("%d %d %d", &x, &p, &k);
        p = a[p];
        if (!ris[p]) {
			ris[p] = 1;
			int m = sqrt(p);
			f1(i, 1, m) if (p % i == 0) v[p].pb(i);
			int sz = v[p].size();
			if (p == m * m) sz --;
			f3(i, sz-1, 0) v[p].pb(p/v[p][i]);
        }
        int u = calc(x, v[p]);
        k += u;
        int now = k;
        while (1) {
			x = calc(now, v[p]);
            if (x == k) break;
            else now += k - x;
        }
        printf("%d\n", now);
	}
	return 0;
}