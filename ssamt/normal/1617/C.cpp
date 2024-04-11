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
		sort(a, a+n);
		vector<int> others;
		int check[n+1] = {};
		for(i=0; i<n; i++) {
			if(a[i] > n || check[a[i]]) {
				others.push_back(a[i]);
			} else {
				check[a[i]] = 1;
			}
		}
		vector<int> left;
		for(i=1; i<=n; i++) {
			if(!check[i]) {
				left.push_back(i);
			}
		}
		int found = 1;
		for(i=0; i<others.size(); i++) {
			//printf("%d %d\n", left[i], others[i]);
			if(2*left[i] >= others[i]) {
				found = 0;
				break;
			}
		}
		if(found) {
			printf("%d\n", others.size());
		} else {
			printf("-1\n");
		}
	}
}