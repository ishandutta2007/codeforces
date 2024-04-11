#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		long long x;
		scanf("%d %d %lld", &n, &k, &x);
		x--;
		char s[n+1];
		scanf("%s", s);
		vector<int> at;
		for(i=0; i<n; i++) {
			if(s[i] == '*') {
				if(i == 0 || s[i-1] == 'a') {
					at.push_back(1);
				} else {
					at.back()++;
				}
			}
		}
		int d[at.size()];
		for(i=(int)at.size()-1; i>=0; i--) {
			d[i] = x%(k*at[i]+1);
			x /= k*at[i]+1;
		}
		int idx = 0;
		for(i=0; i<n; i++) {
			if(s[i] == 'a') {
				printf("a");
			} else {
				if(i == 0 || s[i-1] == 'a') {
					for(j=0; j<d[idx]; j++) {
						printf("b");
					}
					idx++;
				}
			}
		}
		printf("\n");
	}
}