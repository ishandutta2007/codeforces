//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l, r;

int main() {
	puts("YES");
	scanf("%lld%lld", &l, &r);
	for(ll i=l;i<=r;i+=2) printf("%lld %lld\n", i, i+1);
	return 0;
}