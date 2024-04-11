#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		long long hc, dc, hm, dm;
		int w;
		long long a;
		scanf("%lld %lld %lld %lld", &hc, &dc, &hm, &dm);
		scanf("%d %d %lld", &k, &w, &a);
		int check = 0;
		for(i=0; i<=k; i++) {
			if((hm-1)/(dc+i*w)+1 <= (hc+(k-i)*a-1)/dm+1) {
				check = 1;
			}
		}
		if(check) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}