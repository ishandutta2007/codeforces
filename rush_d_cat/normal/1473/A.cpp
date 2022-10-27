#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t, n, d, a[N];
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d",&n,&d);
		bool flag = 0;
		for(int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			if (a[i] > d) flag = 1;
		}
		if (flag == 0) printf("YES\n");
		else {
			sort(a+1,a+1+n);
			if (a[1] + a[2] <= d) printf("YES\n");
			else printf("NO\n");
		}
	}
}