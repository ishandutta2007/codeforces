#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int N = 3005;

template <typename T> inline void read(T &WOW) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	WOW = flag * x;
}

int n, zero[N];
LL k, a[N], sum[N];

void solve() {
    read(n); read(k);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        sum[i] = sum[i - 1] + a[i];
        zero[i] = zero[i - 1] + (a[i] == 0);
    }
    if (k * zero[n] < llabs(sum[n])) {
        puts("-1");
        return;
    }

    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            LL lmx = sum[i - 1] + k * zero[i - 1];
            LL lmn = sum[i - 1] - k * zero[i - 1];
            LL rmx = sum[n] - sum[j] + k * (zero[n] - zero[j]);
            LL rmn = sum[n] - sum[j] - k * (zero[n] - zero[j]);
            LL mx = sum[j] - sum[i - 1] + k * (zero[j] - zero[i - 1]);
            LL mn = sum[j] - sum[i - 1] - k * (zero[j] - zero[i - 1]);
            if (lmn <= 0 && rmn <= 0) {
                ans = max(ans, min(- lmn - rmn, mx));
            }
            if (lmx >= 0 && rmx >= 0) {
                ans = max(ans, min(lmx + rmx, -mn));
            }
        }
    }
    printf("%lld\n", ans + 1);
}

int main() {
    solve();
    return 0;
}