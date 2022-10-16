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

int n, a[N], b[N], t;

bool inline chk(int x) {
	t = 0;
	for (int i = 1; i <= n; i++) if (a[i] != x) b[++t] = a[i];
	for (int i = 1; i <= t; i++) if (b[i] != b[t - i + 1]) return 0;
	return 1;
}
 
int main() {
	int T; read(T);
	while (T--) {
		read(n);
		for (int i = 1; i <= n; i++) read(a[i]);
		int l = 1, r = n;
		while (l <= r && a[l] == a[r]) l++, r--;
		if (l > r) puts("YES");
		else {
			if (chk(a[l])) puts("YES");
			else if (chk(a[r])) puts("YES");
			else puts("NO");
		}
	}
    return 0;
}