#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		int l, r;
		scanf("%d %d %d %d", &n, &l, &r, &k);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		vector<int> b;
		for(i=0; i<n; i++) {
			if(l<=a[i] && a[i]<=r) {
				b.push_back(a[i]);
			}
		}
		sort(b.begin(), b.end());
		i = 0;
		while(i<b.size()) {
			k -= b[i];
			if(k < 0) {
				break;
			}
			i++;
		}
		printf("%d\n", i);
	}
}