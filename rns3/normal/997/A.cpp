#include <bits/stdc++.h>

using namespace std;



#define N 303030



int n, a, b;

char s[N];



int main() {

	//freopen("r.in", "r", stdin);

	scanf("%d %d %d %s", &n, &a, &b, s + 1);

	int cnt = 0;

	s[0] = '1';

	for (int i = 1; i <= n; i ++) if (s[i-1] == '1' && s[i] == '0') cnt ++;

	if (!cnt) {

		puts("0");

		return 0;

	}

	long long ans = b + 1ll * min(a, b) * (cnt - 1);

	printf("%I64d\n", ans);



	return 0;

}