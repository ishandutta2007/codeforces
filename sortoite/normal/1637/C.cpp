#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
long long solve() {
	int n; scanf("%d", &n);
	long long sum = 0;
	bool find = false;
	int odd = 0;
	for(int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
		if(1 < i && i < n) {
			if(a[i] > 1) {
				find = true;
			}
			odd += a[i] & 1;
			sum += a[i];
		}
	}
	if(odd && n == 3) {
		return -1;
	}
	if(odd && !find) {
		return -1;
	}
	return (sum + odd) / 2;
}
int main() {
#ifdef TRUE
	freopen("in.in", "r", stdin);
#endif
	int T; cin >> T;
	while(T --) {
		printf("%I64d\n", solve());
	}
	return 0;
}