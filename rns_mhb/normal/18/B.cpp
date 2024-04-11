#include <bits/stdc++.h>
using namespace std;

int n, d, m, l, k;
long long u, v;

int main(){
	int i;
	scanf("%d %d %d %d", &n, &d, &m, &l);
	v = 1ll * m * (n - 1) + l;
	for(i = 0; i < n; i++){
		u = 1ll * ((l + 1ll * m * i) / d + 1) * d;
		if((u % m) > l || u > v) break;
	}
	printf("%I64d\n", u);
}