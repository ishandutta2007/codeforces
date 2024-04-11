#include <bits/stdc++.h>
using namespace std;
#define M 200010
typedef long long LL;
int a[M], b[M], c[M];
int n, m;
LL B, C;

int main() {
	//freopen("C.in", "r", stdin);
	scanf("%d %d %I64d %I64d", &n, &m, &B, &C);
	B = min(B, 5 * C);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	LL ans = (1LL << 62);
	for (int r = 0; r < 5; r++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] % 5 != r) {
				c[i] = (r - (a[i] % 5) + 5) % 5;
			}
			else c[i] = 0;
			b[i] = (a[i] + c[i] - r) / 5;
		}
		LL sum = 0;
		priority_queue <LL, vector <LL> > q;
		for (int i = 0; i < m; i++) {
			LL tp = C * c[i] + B * (b[m-1] - b[i]);
			q.push(tp); sum += tp;
		}
		if (ans > sum) ans = sum;
		LL D = 0;
		for (int i = m; i < n; i++) {
			LL mx = q.top(); q.pop();
			sum -= (mx + D);
			sum += B * (m - 1) * (b[i] - b[i-1]) + C * c[i];
			D = (b[i] - b[m-1]) * B;
			q.push(c[i] * C - D);
			if (ans > sum) ans = sum;
		}
	}
	cout << ans << endl;
}