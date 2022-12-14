#include <bits/stdc++.h>

using namespace std;



int main() {

	//freopen("r.in", "r", stdin);

	int n;

	int mx = 0;

	scanf("%d", &n);

	for (int i = 1, x; i <= n; i ++) {

		scanf("%d", &x);

		mx = max(x, mx);

	}

	printf("%d\n", max(0, mx - 25));



	return 0;

}