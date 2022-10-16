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

int n, a[N], b[N], R[N];


bool inline chk(int x) {
	int L = 0, R = 0;
	for (int i = 1; i <= n; i++) {
		int l = max(1, x - b[i]), r = min(x, 1 + a[i]);
		if (l > r) continue;
		int gL = max(L, l - 1);
		int gR = min(R, r - 1);
		if (gL <= gR) {
			chkMin(L, gL + 1);
			chkMax(R, gR + 1);
		}
		if (R == x) return 1;
	}
	return 0;
}

int main() {
	int T; read(T);
	while (T--) {
		read(n);
		for (int i = 1; i <= n; i++) read(b[i]), read(a[i]);
		int l = 1, r = n;
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			if (chk(mid)) l = mid;
			else r = mid - 1;
		}
		printf("%d\n", r);
	}
    return 0;
}