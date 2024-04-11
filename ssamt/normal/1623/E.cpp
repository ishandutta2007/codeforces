#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	int in;
	scanf("%d %d", &n, &m);
	char s[n+1];
	scanf("%s", s);
	int l[n], r[n];
	int p[n];
	for(i=0; i<n; i++) {
		scanf("%d %d", &l[i], &r[i]);
		l[i]--;
		r[i]--;
		if(l[i] != -1) {
			p[l[i]] = i;
		}
		if(r[i] != -1) {
			p[r[i]] = i;
		}
	}
	vector<int> a;
	function<void(int)> find_order = [&](int idx) {
		if(l[idx] != -1) {
			find_order(l[idx]);
		}
		a.push_back(idx);
		if(r[idx] != -1) {
			find_order(r[idx]);
		}
	};
	find_order(0);
	/*for(i=0; i<n; i++) {
		printf("%d ", a[i]);
	}*/
	int two[n];
	for(i=0; i<n; i++) {
		for(j=i; j<n && s[a[i]]==s[a[j]]; j++);
		if(j == n || s[a[j]] < s[a[i]]) {
			for(k=i; k<j; k++) {
				two[a[k]] = 0;
			}
		} else {
			for(k=i; k<j; k++) {
				two[a[k]] = 1;
			}
		}
		i = j-1;
	}
	/*for(i=0; i<n; i++) {
		printf("%d ", two[i]);
	}*/
	int take[n];
	for(i=0; i<n; i++) {
		take[i] = -1;
	}
	function<void(int, int, int)> solve = [&](int idx, int top, int h) {
		if(l[idx] != -1) {
			if(take[idx] == 0) {
				take[l[idx]] = 0;
			}
			if(take[idx] == 1) {
				solve(l[idx], h, h+1);
			} else {
				solve(l[idx], top, h+1);
			}
		}
		if(take[idx] == -1) {
			if(two[idx]) {
				if(m >= h-top) {
					int node = idx;
					for(i=0; i<h-top; i++) {
						take[node] = 1;
						node = p[node];
						m--;
					}
				}
			}
			if(take[idx] != 1) {
				take[idx] = 0;
			}
		}
		if(r[idx] != -1) {
			if(take[idx] == 0) {
				take[r[idx]] = 0;
			}
			solve(r[idx], h, h+1);
		}
	};
	solve(0, 0, 1);
	for(i=0; i<n; i++) {
		if(take[a[i]]) {
			printf("%c%c", s[a[i]], s[a[i]]);
		} else {
			printf("%c", s[a[i]]);
		}
	}
	printf("\n");
}