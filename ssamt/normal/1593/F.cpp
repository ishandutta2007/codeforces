#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <functional>

using namespace std;

int main() {
	int h, i, j, k, l;
	int t, n, m, q;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		int a, b;
		scanf("%d %d %d", &n, &a, &b);
		char s[n];
		scanf("%s", s);
		int x[n];
		for(i=0; i<n; i++) {
			x[i] = s[i]-'0';
		}
		vector<int> d[n+1][a][b][n+1];
		d[0][0][0][0] = vector<int>{0, 0, -1};
		for(i=0; i<n; i++) {
			for(j=0; j<a; j++) {
				for(k=0; k<b; k++) {
					for(l=0; l<=n; l++) {
						if(d[i][j][k][l].size() > 0) {
							int red = (j*10+x[i])%a;
							if(d[i+1][red][k][l+1].size() == 0) {
								d[i+1][red][k][l+1] = vector<int>{j, k, 0};
							}
							int black = (k*10+x[i])%b;
							if(d[i+1][j][black][l].size() == 0) {
								d[i+1][j][black][l] = vector<int>{j, k, 1};
							}
						}
					}
				}
			}
		}
		int red_num = 0;
		for(i=1; i<n; i++) {
			if(d[n][0][0][i].size() > 0) {
				if(abs(i-(n-i)) < abs(red_num-(n-red_num))) {
					red_num = i;
				}
			}
		}
		if(red_num > 0) {
			vector<int> part;
			int red = 0, black = 0;
			for(i=n; i>0; i--) {
				part.push_back(d[i][red][black][red_num][2]);
				int red_save = d[i][red][black][red_num][0];
				int black_save = d[i][red][black][red_num][1];
				if(d[i][red][black][red_num][2] == 0) {
					red_num--;
				}
				red = red_save, black = black_save;
			}
			for(i=part.size()-1; i>=0; i--) {
				if(part[i] == 0) {
					printf("R");
				} else {
					printf("B");
				}
			}
			printf("\n");
		} else {
			printf("-1\n");
		}
	}
}