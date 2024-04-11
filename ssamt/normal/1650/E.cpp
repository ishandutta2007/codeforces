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
		int d;
		scanf("%d %d", &n, &d);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
			a[i]--;
		}
		int diff[n];
		diff[0] = a[0];
		for(i=1; i<n; i++) {
			diff[i] = a[i]-a[i-1]-1;
		}
		int small = *min_element(diff, diff+n);
		int count = 0;
		for(i=0; i<n; i++) {
			if(a[i] == small) {
				count++;
			}
		}
		if(count > 2) {
			printf("%d\n", small);
		} else {
			int mu = small;
			int idx = min_element(diff, diff+n)-diff;
			if(idx != 0) {
				vector<int> next;
				for(i=0; i<n; i++) {
					if(i == idx-1) {
						;
					} else if(i == idx) {
						next.push_back(diff[idx]+diff[idx-1]+1);
					} else {
						next.push_back(diff[i]);
					}
				}
				int large = *max_element(next.begin(), next.end());
				int small = min(*min_element(next.begin(), next.end()), max((large-1)/2, d-2-a[n-1]));
				mu = max(mu, small);
			}
			if(idx != n-1) {
				vector<int> next;
				for(i=0; i<n; i++) {
					if(i == idx+1) {
						;
					} else if(i == idx) {
						next.push_back(diff[idx]+diff[idx+1]+1);
					} else {
						next.push_back(diff[i]);
					}
				}
				int large = *max_element(next.begin(), next.end());
				int small = min(*min_element(next.begin(), next.end()), max((large-1)/2, d-2-a[n-1]));
				mu = max(mu, small);
			}
			if(idx == n-1) {
				vector<int> next;
				for(i=0; i<n-1; i++) {
					next.push_back(diff[i]);
				}
				int large = *max_element(next.begin(), next.end());
				int small = min(*min_element(next.begin(), next.end()), max((large-1)/2, d-2-a[n-2]));
				mu = max(mu, small);
			}
			printf("%d\n", mu);
		}
	}
}