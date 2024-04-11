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
		scanf("%d", &n);
		vector<int> idx{0, 1};
		int ex;
		for(i=2; i<n; i+=2) {
			idx.push_back(i);
			if(i == n-1) {
				idx.push_back(ex);
			} else {
				idx.push_back(i+1);
			}
			vector<vector<int>> val;
			for(j=0; j<4; j++) {
				printf("? ");
				for(k=0; k<4; k++) {
					if(j != k) {
						printf("%d ", idx[k]+1);
					}
				}
				printf("\n");
				fflush(stdout);
				scanf("%d", &in);
				val.push_back({in, j});
			}
			sort(val.begin(), val.end());
			vector<int> temp{idx[val[0][1]], idx[val[1][1]]};
			ex = idx[val[2][1]];
			idx = temp;
		}
		printf("! %d %d\n", idx[0]+1, idx[1]+1);
		fflush(stdout);
	}
}