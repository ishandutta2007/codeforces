#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

ll fib[66], pfib[66];
int K;
int a[105];

void solve() {
	scanf("%d", &K);
	ll as = 0;
	for (int i = 1; i <= K; ++i) scanf("%d", a + i), as += a[i];
	int pf = -1;
	for (int i = 1; i <= 60; ++i) if (pfib[i] == as) pf = i;
	if (!~pf) return void(puts("no"));
	priority_queue<int> pq;
	for (int i = 1; i <= K; ++i) pq.push(a[i]);
	int lstsel = 0;
	for (int i = pf; i; --i) {
		if (!SZ(pq)) return void(puts("NO"));
		int t = pq.top();
		pq.pop();
		if (t < fib[i]) return void(puts("No"));
		t -= fib[i];
		if (lstsel) pq.push(lstsel);
		lstsel = t;
	}
	if (!SZ(pq)) return void(puts("yes"));
	else return void(puts("nO"));
}

int main() {
	fib[1] = fib[2] = 1;
	for (int i = 3; i <= 60; ++i) fib[i] = fib[i - 1] + fib[i - 2];
	for (int i = 1; i <= 60; ++i) pfib[i] = fib[i] + pfib[i - 1];
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}