#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int a[N];
int main() {
#ifdef TRUE
	freopen("in.in", "r", stdin);
#endif
	int T; cin >> T;
	while(T --) {
		int n, b = 0;
		scanf("%d", &n);
		for(int i = 0; i < n; i ++) {
			scanf("%d", a + i);
			if(i && a[i] < a[i - 1]) b = 1;
		}
		puts(!b ? "NO" : "YES");
	}
	return 0;
}