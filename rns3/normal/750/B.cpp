#include <bits/stdc++.h>
using namespace std;

const int K = 20000;

int a;
char s[1010];

int main() {
	//freopen("r.in", "r", stdin);
	int t;
	scanf("%d", &t);
	int now = 0;
	bool flag = 0;
	while (t --) {
		scanf("%d %s", &a, s);
		if (now == 0 && s[0] != 'S') flag = 1;
		if (now == K && s[0] != 'N') flag = 1;
		if (s[0] == 'S') now += a;
		else if (s[0] == 'N') now -= a;
		if (now < 0 || now > K) flag = 1;
	}
	if (now) flag = 1;
	if (flag) puts("NO");
	else puts("YES");
	return 0;
}