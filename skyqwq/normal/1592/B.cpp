// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e5 + 5;

int n, x, a[N], b[N];
 
int main() {
	int T; read(T);
	while (T--) {
		read(n), read(x);
		int l = n - x + 1, r = x;
		for (int i = 1; i <= n; i++) read(a[i]), b[i] = a[i];
		sort(b + 1, b + 1 + n);
		bool o = 1;
		for (int i = l; i <= r; i++)
			if (a[i] != b[i]) o = 0;
		puts(o ? "YES" : "NO");
	}
	return 0;
}