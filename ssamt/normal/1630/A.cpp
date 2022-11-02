#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &k);
		if(n == 4 && k == 3) {
			printf("-1\n");
		} else {
			int a[n];
			for(i=0; i<n; i++) {
				a[i] = i;
			}
			int d;
			for(d=0; !(n&(1<<d)); d++);
			vector<int> kd;
			for(i=0; i<d; i++) {
				if(k&(1<<i)) {
					kd.push_back(1<<i);
				}
			}
			kd.push_back(0);
			//printf("%d\n", i);
			for(i=1; i<kd.size(); i++) {
				a[kd[i-1]] = kd[i];
			}
			if(kd.size() )
			a[kd.back()] = kd[0];
			for(i=0; i<n/2; i++) {
				printf("%d %d\n", a[i], a[n-i-1]);
			}
		}
	}
}