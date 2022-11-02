#include <bits/stdc++.h>
using namespace std;

#define N 300030
int a[N], n, k;

bool query(int l, int r){
	int k = upper_bound(a, a + n, l) - a;
	return a[k] < r;
}

int main() {
	///freopen("a.in", "r", stdin);
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i ++) scanf("%d", a + i);
	sort(a, a + n);
	n = unique(a, a + n) - a;
	a[n] = 10000000;

//	for(int i = 0; i < n; i ++) printf("%d ", a[i]); puts("");
//	cout << query(17, 21);

	for(int ans = a[0]; ans > k; ans --){
		bool fg = true;
		for(int j = 0; j <= a[n - 1] / ans; j ++){
			if( query(ans * j + k, ans * j + ans) ){ fg = false; break; }
		}
		if(fg){ printf("%d\n", ans); return 0; }
	}
	cout << a[0] << endl;
}