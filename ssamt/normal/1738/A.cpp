#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		scanf("%d", &n);
		vector<int> a(n), b(n);
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		for(i=0; i<n; i++) {
			scanf("%d", &b[i]);
		}
		vector<vector<int>> s(2);
		for(i=0; i<n; i++) {
			s[a[i]].push_back(b[i]);
		}
		sort(s[0].begin(), s[0].end());
		sort(s[1].begin(), s[1].end());
		long long answer = 0;
		if(s[0].size() == s[1].size()) {
			for(i=0; i<2; i++) {
				for(j=0; j<s[i].size(); j++) {
					answer += 2*s[i][j];
				}
			}
			answer -= min(s[0][0], s[1][0]);
		} else {
			int idx = (s[0].size()>s[1].size())?0:1;
			for(i=0; i<s[idx].size()-s[1-idx].size(); i++) {
				answer += s[idx][i];
			}
			for(; i<s[idx].size(); i++) {
				answer += 2*s[idx][i];
			}
			for(i=0; i<s[1-idx].size(); i++) {
				answer += 2*s[1-idx][i];
			}
		}
		printf("%lld\n", answer);
	}
}