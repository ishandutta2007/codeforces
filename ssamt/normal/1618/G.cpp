#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d %d %d", &n, &m, &q);
	vector<vector<int>> count;
	long long current = 0;
	for(i=0; i<n; i++) {
		scanf("%d", &in);
		count.push_back({in, 1});
		current += in;
	}
	for(i=0; i<m; i++) {
		scanf("%d", &in);
		count.push_back({in, 0});
	}
	n = count.size();
	sort(count.begin(), count.end());
	long long sum[n+1];
	sum[0] = 0;
	for(i=0; i<n; i++) {
		sum[i+1] = sum[i]+count[i][0];
	}
	vector<vector<int>> diff;
	for(i=0; i<n-1; i++) {
		diff.push_back({count[i+1][0]-count[i][0], i});
	}
	sort(diff.begin(), diff.end());
	vector<vector<int>> qs;
	for(ql=0; ql<q; ql++) {
		scanf("%d", &in);
		qs.push_back({in, ql});
	}
	sort(qs.begin(), qs.end());
	int left[n], right[n];
	for(i=0; i<n; i++) {
		left[i] = i;
		right[i] = i;
	}
	int dpos = 0;
	long long answer[q];
	for(ql=0; ql<q; ql++) {
		while(dpos < n-1 && diff[dpos][0] <= qs[ql][0]) {
			int lidx = diff[dpos][1];
			int ridx = right[lidx+1];
			int num = count[lidx][1];
			//printf("%d %d %d %d\n", ql, lidx, ridx, num);
			current -= sum[lidx+1]-sum[lidx+1-num];
			current += sum[ridx+1-count[ridx][1]]-sum[ridx+1-count[ridx][1]-num];
			count[ridx][1] += count[lidx][1];
			count[lidx][1] = 0;
			right[left[lidx]] = ridx;
			left[ridx] = left[lidx];
			dpos++;
			//printf("%lld\n", current);
		}
		answer[qs[ql][1]] = current;
	}
	for(ql=0; ql<q; ql++) {
		printf("%lld ", answer[ql]);
	}
	printf("\n");
}