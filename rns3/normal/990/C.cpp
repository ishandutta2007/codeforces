#include <bits/stdc++.h>

using namespace std;



#define N 303030



char s[N];

int a[N];



const int INF = 1e9;



int le[N], ri[N];



int main() {

	//freopen("r.in", "r", stdin);

	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i ++) {

		scanf("%s", s);

		int m = strlen(s);

		int cnt = 0, mn = 0;

		for (int j = 0; j < m; j ++) {

			if (s[j] == '(') cnt ++;

			else cnt --;

			mn = min(mn, cnt);

		}

		a[i] = cnt;

		if (!cnt) {

			if (mn < 0) a[i] = INF;

		}

		else if (cnt > 0) {

			if (mn < 0) a[i] = INF;

		}

		else {

			if (mn < cnt) a[i] = INF;

		}

	}

	int zero = 0;

	for (int i = 1; i <= n; i ++) if (a[i] < INF) {

		if (!a[i]) zero ++;

		else if (a[i] < 0) le[-a[i]] ++;

		else ri[a[i]] ++;

	}

	long long ans = 1ll * zero * zero;

	for (int i = 1; i < N; i ++) ans += 1ll * le[i] * ri[i];

	printf("%I64d\n", ans);



	return 0;

}