#include <bits/stdc++.h>

using namespace std;
using INT = long long;

int disp(int a, int b, int c) {
			printf("%d %d %d\n", a, b, c);
			return 0;
		}
		
int solve() {
	INT l, r, m;
	cin >> l >> r >> m;
	int b, c;
	for(int a=l; a<=r; a++) {
		int n = m/a;
		int re = m%a;
		if(n and re <= r-l) {
			b = r;
			c = r - re;
			return disp(a, b, c);
		}
		n = m/a+1;
		re = a-re;
		if(re <= r-l) {
			c = r;
			b = r - re;
			return disp(a, b, c);
		}
	}
}

int main (){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int T;
	cin >> T;
	while(T--) solve();

	return 0;
}