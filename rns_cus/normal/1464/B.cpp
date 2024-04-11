#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, x, y, cnt[N][2];
char s[N];
typedef long long ll;
ll ans, add[N][2];

inline int get_0(int l, int r) {
	if (l > r) return 0;
	return cnt[r][0] - cnt[l-1][0];
}

inline int get_1(int l, int r) {
	if (l > r) return 0;
	return cnt[r][1] - cnt[l-1][1];
}

ll calc(int c) {
	ll rlt = 1e18, tot = 0, cur = 0;
	int cnt = 0, oth = 0, cost = (c == 0 ? x : y);
	for (int i = 1; i <= n; i ++) if (s[i] == '?') tot += add[i][c^1], oth ++;
	rlt = min(rlt, tot);
	for (int i = 1; i <= n; i ++) if (s[i] == '?') {
		cur += add[i][c], tot -= add[i][c^1];
		cnt ++, oth --;
		rlt = min(rlt, cur + tot + 1ll * cnt * oth * cost);
	}
	return rlt + ans;
}

int main() {
    scanf("%s", s + 1);
    scanf("%d %d", &x, &y);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i ++) {
		cnt[i][0] = cnt[i-1][0] + (s[i] == '0');
		cnt[i][1] = cnt[i-1][1] + (s[i] == '1');
    }
    for (int i = 1; i <= n; i ++) {
		if (s[i] == '0') ans += 1ll * y * get_1(1, i - 1);
		else if (s[i] == '1') ans += 1ll * x * get_0(1, i - 1);
		else {
			add[i][0] = 1ll * y * get_1(1, i - 1) + 1ll * x * get_1(i + 1, n);
			add[i][1] = 1ll * x * get_0(1, i - 1) + 1ll * y * get_0(i + 1, n);
		}
    }
    printf("%lld\n", min(calc(0), calc(1)));

    return 0;
}