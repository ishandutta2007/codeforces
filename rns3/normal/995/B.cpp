#include <bits/stdc++.h>

using namespace std;



#define N 202



int n, a[N];

int L[N], R[N];

int go[N];



int main() {

	//freopen("r.in", "r", stdin);

	scanf("%d", &n);

	int cnt = 0;

	for (int i = 1; i <= n * 2; i ++) {

		scanf("%d", &a[i]);

		if (!L[a[i]]) {

			L[a[i]] = i, cnt ++;

			go[i] = cnt * 2 - 1;

		}

		else {

			R[a[i]] = i;

			go[i] = go[L[a[i]]] + 1;

		}

	}

	int ans = 0;

	for (int i = 1; i < n * 2; i ++) for (int j = i + 1; j <= n * 2; j ++) if (go[i] > go[j]) ans ++;

	printf("%d\n", ans);



	return 0;

}