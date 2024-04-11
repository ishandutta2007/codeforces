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

const int N = 1048580;

int n, a[N], c[2][N], b[N], s[N], ans;
 
int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int w = 19; ~w; w--) {
		for (int i = 1; i <= n; i++) {
			if (!(a[i] >> w & 1)) continue;
			int j = i;
			while (j < n && (a[j + 1] >> w & 1)) j++;
			for (int k = i; k <= j; k++) {
				int ch = k & 1;
				if (c[!ch][s[k]]) chkMax(ans, k - c[!ch][s[k]] + 1);
				if (!c[ch][s[k - 1]]) c[ch][s[k - 1]] = k;
			}
			for (int k = i; k <= j; k++) {
				int ch = k & 1;
				c[ch][s[k - 1]] = 0;
			}
			i = j;
		}
		for (int j = 1; j <= n; j++) {
			if (a[j] >> w & 1) b[j] |= 1 << w;
			s[j] = s[j - 1] ^ b[j];
		}
	}
	printf("%d\n", ans);
	return 0;
}