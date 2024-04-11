#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << H << ' ';
	debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 0
#endif

#define N 100100

int n, a[N], b[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
		scanf("%d", &n);
		int na = 0, nb = 0;
		for (int i = 0, x, y; i < 2 * n; i ++) {
			scanf("%d %d", &x, &y);
			if (x == 0) a[++na] = y;
			else b[++nb] = x;
		}
		for (int i = 1; i <= n; i ++) a[i] = abs(a[i]), b[i] = abs(b[i]);
		sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);
		double ans = 0;
		for (int i = 1; i <= n; i ++) ans += sqrt(1ll * a[i] * a[i] + 1ll * b[i] * b[i]);
		printf("%.11f\n", ans);
    }

    return 0;
}