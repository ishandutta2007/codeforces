#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t;
LL a, b, c;
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a<c) printf("1 "); else printf("-1 ");
		if(c<a*b) printf("%lld\n", b); else printf("-1\n");
	}
}