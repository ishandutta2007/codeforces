#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int main() {
	int h, i, j, l;
	int t, n, m;
	scanf("%d %d", &n, &m);
	int rt = (int)sqrt(n);
	int x[n], y[n];
	for(i=0; i<n; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	int op[m], k[m];
	for(i=0; i<m; i++) {
		scanf("%d %d", &op[i], &k[i]);
		k[i]--;
	}
	int d[m] = {};
	vector<vector<int> > p[rt+1][2];
	int last[n] = {};
	for(i=0; i<m; i++) {
		int period = x[k[i]]+y[k[i]];
		if(period <= rt) {
			if(op[i] == 1) {
				last[k[i]] = i;
			}
			vector<int> e{k[i], i, last[k[i]]};
			p[period][op[i]-1].push_back(e);
		}
	}
	/*for(i=0; i<=rt; i++) {
		printf("p[%d]\n", i);
		for(h=0; h<2; h++) {
			for(j=0; j<p[i][h].size(); j++) {
				printf("%d %d %d\n", p[i][h][j][0], p[i][h][j][1], p[i][h][j][2]);
			}
			printf("\n");
		}
	}*/
	for(i=2; i<=rt; i++) {
		if(!p[i][0].empty()) {
			int dp[i] = {};
			int p_idx[2] = {};
			for(j=0; j<m; j++) {
				while(p_idx[1] < p[i][1].size() && p[i][1][p_idx[1]][1] == j) {
					if((p[i][1][p_idx[1]][2]+x[p[i][1][p_idx[1]][0]]-(j%i)+i)%i > (p[i][1][p_idx[1]][2]-(j%i)+i)%i) {
						d[j]--;
					}
					dp[p[i][1][p_idx[1]][2]%i]++;
					dp[(p[i][1][p_idx[1]][2]+x[p[i][1][p_idx[1]][0]])%i]--;
					p_idx[1]++;
				}
				while(p_idx[0] < p[i][0].size() && p[i][0][p_idx[0]][1] == j) {
					d[j]++;
					dp[j%i]--;
					dp[(j+x[p[i][0][p_idx[0]][0]])%i]++;
					p_idx[0]++;
				}
				d[j] += dp[j%i];
				/*printf("%d\n", i);
				for(h=0; h<i; h++) {
					printf("%d ", dp[h]);
				}
				printf("\n");*/
			}
		}
	}
	vector<int> change[n];
	for(i=0; i<m; i++) {
		change[k[i]].push_back(i);
	}
	for(i=0; i<n; i++) {
		if(x[i]+y[i] > rt) {
			for(j=0; j<(int)change[i].size()-1; j+=2) {
				for(l=change[i][j]; l+x[i]+y[i]<change[i][j+1]; l+=x[i]+y[i]) {
					d[l+x[i]]++;
					d[l+x[i]+y[i]]--;
				}
				if(l+x[i] < change[i][j+1]) {
					d[l+x[i]]++;
					d[change[i][j+1]]--;
				}
			}
			if(change[i].size()%2 == 1) {
				for(l=change[i].back(); l+x[i]+y[i]<m; l+=x[i]+y[i]) {
					d[l+x[i]]++;
					d[l+x[i]+y[i]]--;
				}
				if(l+x[i] < m) {
					d[l+x[i]]++;
				}
			}
		}
	}
	int sum = 0;
	for(i=0; i<m; i++) {
		sum += d[i];
		printf("%d\n", sum);
	}
}