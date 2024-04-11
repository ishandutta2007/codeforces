#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		int x;
		scanf("%d", &n);
		int a[n];
		int s[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
			s[i] = a[i];
		}
		sort(s, s+n);
		int check = 1;
		for(i=0; i<n; i+=2) {
			if(s[i] != s[i+1]) {
				check = 0;
			}
		}
		if(n%2 == 1) {
			check = 0;
		}
		if(check) {
			int shift = 0;
			vector<vector<int>> ops; //0-index
			vector<int> cut;
			vector<int> b;
			for(i=0; i<n; i++) {
				b.push_back(a[i]);
			}
			for(i=0; i<n/2; i++) {
				for(j=1; j<b.size(); j++) {
					if(b[j] == b[0]) {
						break;
					}
				}
				int idx = j;
				for(j=1; j<idx; j++) {
					ops.push_back({shift+idx+j, b[j]});
				}
				vector<int> temp;
				for(j=1; j<idx; j++) {
					temp.push_back(b[idx-j]);
				}
				for(j=idx+1; j<b.size(); j++) {
					temp.push_back(b[j]);
				}
				b.clear();
				for(j=0; j<temp.size(); j++) {
					b.push_back(temp[j]);
				}
				shift += 2*idx;
				cut.push_back(2*idx);
			}
			printf("%d\n", ops.size());
			for(i=0; i<ops.size(); i++) {
				printf("%d %d\n", ops[i][0], ops[i][1]);
			}
			printf("%d\n", cut.size());
			for(i=0; i<cut.size(); i++) {
				printf("%d ", cut[i]);
			}
			printf("\n");
		} else {
			printf("-1\n");
		}
	}
}