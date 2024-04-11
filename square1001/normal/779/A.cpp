#include <bits/stdc++.h>
using namespace std;
int n, a, b, c[109], d[109];
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a), a--, c[a]++, d[a]++;
	for(int i = 0; i < n; i++) scanf("%d", &b), b--, d[b]++;
	bool f = true;
	for(int i = 0; i < 5; i++) {
		if(d[i] % 2 == 1) f = false;
		d[i] /= 2;
	}
	if(!f) printf("-1\n");
	else {
		int ret = 0;
		for(int i = 0; i < 5; i++) ret += abs(c[i] - d[i]);
		printf("%d\n", ret / 2);
	}
	return 0;
}