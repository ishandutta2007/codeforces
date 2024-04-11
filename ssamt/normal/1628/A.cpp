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
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int mex, next;
		int found[n+1] = {};
		int last[n+1];
		for(i=0; i<=n; i++) {
			last[i] = -1;
		}
		for(i=0; i<n; i++) {
			found[a[i]] = 1;
			last[a[i]] = i;
		}
		for(i=0; i<=n; i++) {
			if(!found[i]) {
				mex = i;
				break;
			}
		}
		int end[n] = {};
		for(i=0; i<=n; i++) {
			if(last[i] != -1) {
				end[last[i]] = 1;
			}
		}
		int idx = 0;
		vector<int> answer;
		while(idx < n) {
			int count = 0;
			next = mex;
			int f[mex] = {};
			while(idx < n && count < mex) {
				if(a[idx] < mex && !f[a[idx]]) {
					f[a[idx]] = 1;
					count++;
				}
				if(end[idx]) {
					next = min(next, a[idx]);
				}
				idx++;
			}
			if(mex == 0) {
				idx++;
			}
			answer.push_back(mex);
			mex = next;
		}
		printf("%d\n", answer.size());
		for(i=0; i<answer.size(); i++) {
			printf("%d ", answer[i]);
		}
		printf("\n");
	}
}