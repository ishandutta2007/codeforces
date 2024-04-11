#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d %d", &n, &q);
	int p[n], ip[n];
	for(i=0; i<n; i++) {
		scanf("%d", &p[i]);
		p[i]--;
	}
	for(i=0; i<n; i++) {
		ip[p[i]] = i;
	}
	int rt = (int)sqrt(n);
	int rp[n];
	for(i=0; i<n; i++) {
		rp[i] = i;
		for(j=0; j<rt; j++) {
			rp[i] = p[rp[i]];
		}
	}
	for(ql=0; ql<q; ql++) {
		int x, y;
		scanf("%d %d %d", &k, &x, &y);
		if(k == 1) {
			x--, y--;
			swap(p[x], p[y]);
			ip[p[x]] = x;
			ip[p[y]] = y;
			int p1, p2;
			p1 = x, p2 = x;
			for(i=0; i<rt; i++) {
				p2 = ip[p2];
			}
			for(i=0; i<=rt; i++) {
				rp[p2] = p1;
				p1 = p[p1];
				p2 = p[p2];
			}
			p1 = y, p2 = y;
			for(i=0; i<rt; i++) {
				p2 = ip[p2];
			}
			for(i=0; i<=rt; i++) {
				rp[p2] = p1;
				p1 = p[p1];
				p2 = p[p2];
			}
	/*for(i=0; i<n; i++) {
		printf("%d %d %d\n", p[i], ip[i], rp[i]);
	}*/
		} else {
			x--;
			for(i=0; i<y/rt; i++) {
				x = rp[x];
			}
			for(i=0; i<y%rt; i++) {
				x = p[x];
			}
			printf("%d\n", x+1);
		}
	}
}