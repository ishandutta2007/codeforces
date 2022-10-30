#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	int size = 150000;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		vector<int> s[size+1];
		for(i=0; i<n; i++) {
			s[a[i]].push_back(i);
		}
		int answer = -1;
		for(i=1; i<=size; i++) {
			sort(s[i].begin(), s[i].end());
			for(j=1; j<s[i].size(); j++) {
				answer = max(answer, n-(s[i][j]-s[i][j-1]));
			}
		}
		printf("%d\n", answer);
	}
}