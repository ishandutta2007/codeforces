#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		for(i=0; i<n && a[i]==a[n-i-1]; i++);
		if(i == n) {
			printf("YES\n");
		} else {
			int pos[2] = {a[i], a[n-i-1]};
			int res[2] = {1, 1};
			for(i=0; i<2; i++) {
				vector<int> rest;
				for(j=0; j<n; j++) {
					if(pos[i] != a[j]) {
						rest.push_back(a[j]);
					}
				}
				for(j=0; j<rest.size(); j++) {
					if(rest[j] != rest[rest.size()-j-1]) {
						res[i] = 0;
					}
				}
			}
			if(res[0] || res[1]) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}
}