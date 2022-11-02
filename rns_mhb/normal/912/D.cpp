#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define ll long long
#define mp make_pair
typedef pair<ll, int> pli;
int n, m, r, k;
int tp[N<<1];

inline int f(int s, int i) {
	if (s >= 2 * r - 1) {
		if (i == r) return s - 2 * r + 2;
		else return 2;
	}
	else {
		if (i <= s - r) return 2;
		if (i == s - r + 1) return 2 * r - s;
		else return 0;
	}
}
priority_queue<pli> q;
int main() {
	scanf("%d%d%d%d", &n, &m, &r, &k);
	int d = min(r, max(n, m) - r + 1);
	for (int i = 2; i <= 2 * d; i ++) {
		tp[i] = max(((i + 1) >> 1), i + r - 1 - min(n, m));
	}
	ll sum = 0;
	for (int i = 2 * d; i >= 2; i --) {
		if (tp[i] <= min(r, i - 1)) q.push(mp(1ll * tp[i] * (i - tp[i]), i));
	}
	while (1) {
		int i = (q.top()).second; q.pop();
		ll cnt = 1ll * f(n, tp[i]) * f(m, i - tp[i]);
		if (tp[i] * 2 != i) cnt += 1ll * f(m, tp[i]) * f(n, i - tp[i]);
		if (k <= cnt) {
			sum += 1ll * k * tp[i] * (i - tp[i]);
			break;
		}
		sum += 1ll * cnt * tp[i] * (i - tp[i]);
		k -= cnt;
		if (tp[i] < min(min(r, i - 1), max(n, m) - r + 1)) {
			tp[i] ++;
			q.push(mp(1ll * tp[i]*(i-tp[i]), i));
		}
	}
	printf("%.12lf", 1.0 * sum / (1ll * (n - r + 1) * (m - r + 1)));
	return 0;
}