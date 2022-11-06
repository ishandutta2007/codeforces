#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N = 55;

int T, n, a[N];

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		int cnt = 0;
		rep(i, 1, n) {
			scanf("%d", &a[i]);
			if(a[i] != 2) ++cnt;
		}
		printf("%d\n", cnt);
	}
	return 0;
}