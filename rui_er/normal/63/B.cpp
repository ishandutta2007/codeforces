//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
const int N = 105;

int n, k, a[N], ans;

int main() {
	scanf("%d%d", &n, &k);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	do {
		if(a[1] == k) return printf("%d\n", ans), 0;
		for(int i=1;i<=n;i++) {
			if(a[i] < k && a[i] != a[i+1]) ++a[i];
		}
	}while(++ans, true);
	return 0;
}