#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int T, a, b, c;

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d%d", &a, &b, &c);
		printf("1");
		rep(i, 1, a-1) printf("0");
		printf(" ");
		rep(i, 1, b-c+1) printf("9");
		rep(i, 1, c-1) printf("0");
		puts("");
	}
	return 0;
}