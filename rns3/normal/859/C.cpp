#include <bits/stdc++.h>

using namespace std;



#define N 52



int a[N], s[N], f[N];



int main() {

	//freopen("r.in", "r", stdin);

	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);

	for (int i = n; i >= 1; i --) s[i] = s[i+1] + a[i];

	f[n] = a[n];

	for (int k = n - 1; k >= 1; k --) {

		f[k] = max(a[k] + s[k+1] - f[k+1], f[k+1]);

	}

	printf("%d %d\n", s[1] - f[1], f[1]);



	return 0;

}