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
		long long n;
		scanf("%lld", &n);
		char s[200001];
		scanf("%s", s);
		vector<int> c[2];
		for(i=0; s[i]; i++) {
			int idx = (s[i] == 'R');
			if(i == 0 || s[i-1] != s[i]) {
				c[idx].push_back(1);
			} else {
				c[idx].back()++;
			}
		}
		long long sub = 0;
		if(c[0].empty() || c[1].empty()) {
			sub = n*(n-1);
		} else {
			for(i=0; i<2; i++) {
				int sum = 0;
				for(j=0; j<c[i].size(); j++) {
					sum += c[i][j];
				}
				int cur = 1;
				if(i == (s[0] == 'R')) {
					for(j=0; j<min(c[0].size(), c[1].size()); j++) {
						if(j == 0) {
							cur += n-1-sum;
						}
						cur += c[i][j];
						sub += (long long)c[1-i][j]*(n-cur);
					}
				} else {
					for(j=0; j<min(c[0].size(), c[1].size()); j++) {
						sub += (long long)c[1-i][j]*(n-cur);
						if(j == 0) {
							cur += n-1-sum;
						}
						cur += c[i][j];
					}
				}
			}
		}
		printf("%lld\n", n*n-sub);
	}
}