#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		scanf("%d", &n);
		vector<vector<int>> a(n, vector<int>(n));
		for(i=0; i<n; i++) {
			string s;
			cin >> s;
			for(j=0; j<n; j++) {
				a[i][j] = s[j]-'0';
			}
		}
		int all = 0;
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++) {
				all += a[i][j];
			}
		}
		int large = 0;
		for(i=0; i<n; i++) {
			int count = 0;
			for(j=0; j<n; j++) {
				count += a[(i+j)%n][j];
			}
			large = max(large, count);
		}
		printf("%d\n", all-large+n-large);
	}
}