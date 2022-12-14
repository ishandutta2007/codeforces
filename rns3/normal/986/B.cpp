#include <bits/stdc++.h>

using namespace std;



#define N 1010101



int n;

int a[N];

bool vis[N];



int main() {

	//freopen("2.in", "r", stdin);

	//freopen("1.out", "w", stdout);

	while (scanf("%d", &n) > 0) {

		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);

		memset(vis, 0, sizeof vis);

		int cnt = 0;

		for (int i = 1; i <= n; i ++) if (!vis[i]) {

			cnt ++;

			vis[i] = 1;

			for (int j = a[i]; j != i; j = a[j]) vis[j] = 1;

		}//printf("%.10lf\n", 1.0 * cnt / sqrt(1.0 * n));

		if (1.0 * cnt / sqrt(1.0 * n) > 0.21) puts("Petr");

		else puts("Um_nik");



	}



	return 0;

}