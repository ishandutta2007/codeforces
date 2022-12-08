#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 75;
int n, a[N];

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	int ans = n - 1;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			int cnt = 0;
			double d = 1.0 * (a[j] - a[i]) / (j - i);
			for(int k = 1; k <= n; k++)
				if(fabs(a[k] - a[j] - d * (k - j)) > 1e-10) ++cnt;
			ans = min(ans, cnt);
		}
	}
	printf("%d\n", ans);
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}