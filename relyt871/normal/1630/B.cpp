#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 200005;

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

int n, k, a[MAXN], cnt[MAXN];

void solve() {
    read(n); read(k);
    for (int i = 1; i <= n; ++i) {
        cnt[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        ++cnt[a[i]];
    }
    int sum = -n, ans = n * 2, x = -1, y = -1;
    for (int l = 1, r = 0; l <= n; ++l) {
        while (r < n && sum < k) {
            sum += cnt[++r] * 2;
        }
        if (sum >= k) {
            if (r - l < ans) {
                ans = r - l;
                x = l; y = r;
            }
        }
        sum -= cnt[l] * 2;
    }
    printf("%d %d\n", x, y);
    sum = 0;
    int p = 1, lst = 0;
    for (int i = 1; i <= n; ++i) {
        if (x <= a[i] && a[i] <= y) ++sum;
        else --sum;
        if (sum >= p && (p != k || i == n)) {
            printf("%d %d\n", lst + 1, i);
            lst = i;
            ++p;
        }
    }
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}