//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e10;

ll a[3], *p, k, s;
ll interact(ll x) {
	printf("%lld\n", x);
	fflush(stdout);
	ll res;
	scanf("%lld", &res);
	if(!res) exit(0);
	a[--res] += x;
	return res;
}

int main() {
	scanf("%lld%lld%lld", &a[0], &a[1], &a[2]);
	puts("First"); fflush(stdout);
	s = a[0] + a[1] + a[2] + inf;
	k = interact(inf);
	p = &a[k];
	k = interact((*p)*3-s);
	ll _ = 3 - (p - a) - k;
	k = interact((*p)-a[_]);
	return 0;
}