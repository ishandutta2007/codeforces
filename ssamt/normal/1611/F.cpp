#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &k);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		long long sum[n+1] = {};
		for(i=0; i<n; i++) {
			sum[i+1] = sum[i]+a[i];
		}
		priority_queue<vector<long long>> s;
		vector<int> answer(n+1, 0);
		for(int i=0; i<=n; i++) {
			while(!s.empty() && s.top()[0] > sum[i]+k) {
				answer[s.top()[1]] = i-s.top()[1];
				s.pop();
			}
			s.push({sum[i], i});
		}
		while(!s.empty()) {
			answer[s.top()[1]] = n+1-s.top()[1];
			s.pop();
		}
		int max_idx = 0;
		for(i=1; i<=n; i++) {
			if(answer[i] > answer[max_idx]) {
				max_idx = i;
			}
		}
		if(answer[max_idx] == 1) {
			printf("-1\n");
		} else {
			printf("%d %d\n", max_idx+1, max_idx+answer[max_idx]-1);
		}
		
	}
}