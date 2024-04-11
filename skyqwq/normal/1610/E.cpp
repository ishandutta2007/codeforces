// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5;

int n, a[N], ans;

int inline chk(int s) {
	int v = 2 * a[s + 1] - a[s];
	int p = s + 2; int cnt = 2;
	while (1) {
		int now = lower_bound(a + 1, a + 1 + n, v) - a;
		chkMax(p, now);
		if (p == n + 1) return cnt;
		++cnt;
		v = 2 * a[p] - a[s];
		++p;
	}
	return 0;
}
 
int main() {
	int T; read(T);
	while (T--) {
		read(n);
		for (int i = 1; i <= n; i++) read(a[i]);
		ans = 0;
		for (int i = 1; i < n; i++) {
			if (i == 1 || a[i] != a[i - 1]) chkMax(ans, chk(i));
		}
		printf("%d\n", n - ans);
	}
    return 0;
}