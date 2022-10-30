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
		scanf("%d %d", &n, &k);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		map<int, int> count;
		for(i=0; i<n; i++) {
			if(!count.count(a[i])) {
				count[a[i]] = 0;
			}
			count[a[i]]++;
		}
		vector<vector<int>> s;
		for(auto it=count.begin(); it!=count.end(); it++) {
			s.push_back({it->first, it->second});
		}
		sort(s.begin(), s.end());
		for(i=0; i<s.size() && i+k>=s[i][0]; i++);
		vector<vector<int>> r;
		for(; i<s.size(); i++) {
			r.push_back({s[i][1], s[i][0]});
		}
		sort(r.begin(), r.end());
		int left = k;
		for(i=0; i<r.size(); i++) {
			left -= r[i][0];
			if(left < 0) {
				break;
			}
		}
		if(i == r.size()) {
			printf("0\n");
		} else {
			printf("%d\n", (int)r.size()-i);
		}
	}
}