#include <bits/stdc++.h>
using namespace std;
#define N 110
#define ll long long

int n, a[N], b[N];
ll k, d;
ll s;

bool chk() {
	int cnt = 0;
	for (int i = 1; i <= n; i ++) {
		if (b[i] * d < a[i]) {
			s += ((a[i] - 1) / d + 1 - b[i]);
			b[i] = (a[i] - 1) / d + 1;
			cnt ++;
		}
	}
	return cnt;
}

int main() {
	scanf("%d%I64d", &n, &k);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), k += a[i];
	for (int i = 1; i <= n; i ++) b[i] = 1;
	s = n;
	while (1) {
		d = k / s;
		if (!chk()) break;
	}
	cout<<d<<endl;
}