#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		getchar();
		scanf("%d", &n);
		int a[n][2], m[n];
		for(i=0; i<n; i++) {
			for(j=0; j<2; j++) {
				scanf("%d", &a[i][j]);
			}
			scanf("%d", &m[i]);
		}
		int answer[n];
		int variety = 0;
		vector<vector<int>> total;
		for(i=0; i<n; i++) {
			total.push_back({a[i][0]+a[i][1]-m[i], i});
		}
		sort(total.begin(), total.end());
		int start = 0, end = 0;
		while(start < n) {
			for(end=start; end<n && total[end][0]==total[start][0]; end++);
			vector<vector<int>> inter;
			for(i=start; i<end; i++) {
				int idx = total[i][1];
				inter.push_back({total[i][0]-max(0, a[idx][1]-m[idx]), max(0, a[idx][0]-m[idx]), idx});
			}
			sort(inter.begin(), inter.end());
			int reach = -1;
			for(i=0; i<inter.size(); i++) {
				if(inter[i][1] > reach) {
					reach = inter[i][0];
					variety++;
				}
				answer[inter[i][2]] = a[inter[i][2]][0]-reach;
			}
			start = end;
		}
		printf("%d\n", variety);
		for(i=0; i<n; i++) {
			printf("%d %d\n", answer[i], m[i]-answer[i]);
		}
	}
}