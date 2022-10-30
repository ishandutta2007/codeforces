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
		int p[n];
		for(i=0; i<n; i++) {
			scanf("%d", &p[i]);
		}
		char s[n+1];
		scanf("%s", s);
		vector<vector<int>> zero, one;
		int answer[n];
		for(i=0; i<n; i++) {
			if(s[i] == '0') {
				zero.push_back({p[i], i});
			} else {
				one.push_back({p[i], i});
			}
		}
		sort(zero.begin(), zero.end());
		sort(one.begin(), one.end());
		for(i=0; i<zero.size(); i++) {
			answer[zero[i][1]] = i;
		}
		for(i=0; i<one.size(); i++) {
			answer[one[i][1]] = i+zero.size();
		}
		for(i=0; i<n; i++) {
			printf("%d ", answer[i]+1);
		}
		printf("\n");
	}
}