#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	cin >> t;
	for(cl=0; cl<t; cl++) {
		cin >> n;
		vector<long long> a(n);
		for(i=0; i<n; i++) {
			cin >> a[i];
		}
		long long acc = 0;
		vector<vector<long long>> s{{0, 0}};
		for(i=0; i<n; i++) {
			acc ^= a[i];
			s.push_back({acc, i+1});
		}
		sort(s.begin(), s.end());
		vector<vector<int>> inter;
		for(i=1; i<s.size(); i++) {
			if(s[i-1][0] == s[i][0]) {
				inter.push_back({s[i][1], s[i-1][1]});
			}
		}
		sort(inter.begin(), inter.end());
		int end = 0;
		int count = 0;
		for(i=0; i<inter.size(); i++) {
			if(inter[i][1] >= end) {
				end = inter[i][0];
				count++;
			}
		}
		int answer = n-count;
		cout << answer << endl;
	}
}