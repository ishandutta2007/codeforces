#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <vector>

int main() {
	int h, i, j;
	int t, n, k;
	scanf("%d", &t);
	int r[50000][5];
	for(h=0; h<t; h++) {
		scanf("%d %d", &n, &k);
		int e[n][2];
		int con[2*n];
		for(i=0; i<2*n; i++) {
			con[i] = 0;
		}
		for(i=0; i<k; i++) {
			for(j=0; j<2; j++) {
				scanf("%d", &e[i][j]);
				e[i][j]--;
				con[e[i][j]] = 1;
			}
			if(e[i][0] > e[i][1]) {
				int temp = e[i][1];
				e[i][1] = e[i][0];
				e[i][0] = temp;
			}
		}
		std::vector<int> un;
		for(i=0; i<2*n; i++) {
			if(!con[i]) {
				un.push_back(i);
			}
		}
		for(i=0; i<n-k; i++) {
			e[k+i][0] = un[i];
			e[k+i][1] = un[i+n-k];
		}
		int answer = 0;
		for(i=0; i<n; i++) {
			for(j=i+1; j<n; j++) {
				if((e[i][0] < e[j][0] && e[j][0] < e[i][1] && e[i][1] < e[j][1]) || (e[j][0] < e[i][0] && e[i][0] < e[j][1] && e[j][1] < e[i][1])) {
					answer++;
				}
			}
		}
		printf("%d\n", answer);
	}
}