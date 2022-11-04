#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int a[N], b[N];
bool solve() {
	int n, c; cin >> n >> c;
	int mx = c + sqrt(c) * 2 + 100;
	for(int i = 1; i <= c; i ++) a[i] = 0;
	for(int i = 1; i <= mx; i ++) b[i] = 0;
	for(int i = 0; i < n; i ++) {
		int d; scanf("%d", &d);
		a[d] = b[d] = 1;
	}
	for(int i = mx - 1; i > 0; i --) {
		b[i] += b[i + 1];
	}
	if(!a[1]) return false;
	for(int i = 2; i <= c; i ++) {
		int f = 0;
		for(int j = 1; j * i <= c; j ++) {
			if(a[j] && b[j * i] > b[min(mx, j * (i + 1))]) {
				f = 1;
				break;
			}
		}
		if(f != a[i]) {
			return false;
		}
	}
	return true;
}
int main() {
#ifdef TRUE
	freopen("in.in", "r", stdin);
#endif
	int T; cin >> T;
	while(T --) {
		puts(solve() ? "Yes" : "No");
	}
	return 0;
}