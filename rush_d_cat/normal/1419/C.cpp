#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t, n, x, a[N];

int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d", &n, &x);
		bool has=0;
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
			if (a[i] == x) has = 1;
		}
		
		LL s = 0;
		for (int i = 1; i <= n; i ++) {
			s += a[i];
		}

		bool ok = 1;
		for(int i=1;i<=n;i++)if(a[i]!=x)ok=0;
		if(ok) {
			printf("0\n");
		}else{
			if(n*x==s || has) printf("1\n");
			else printf("2\n");
		}
	}
}