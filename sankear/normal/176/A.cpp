#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

const int inf = (int)1e7;

int a[20][200], b[20][200], c[20][200];
int d[200][200];
char buf[20];

int main(){
	//freopen("bridges.in", "r", stdin);
	//freopen("bridges.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < n; i++){
		scanf("%s", buf);
		for(int j = 0; j < m; j++){
			scanf("%d %d %d", &a[i][j], &b[i][j], &c[i][j]);
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j){
				continue;
			}
			for(int z = 0; z <= m; z++){
				for(int h = 0; h <= k; h++){
					d[z][h] = -inf;
				}
			}
			d[0][0] = 0;
			for(int z = 1; z <= m; z++){
				for(int h = 0; h <= k; h++){
					for(int x = 0; x <= min(c[i][z - 1], h); x++){
						if(d[z - 1][h - x] == -inf){
							continue;
						}
						d[z][h] = max(d[z][h], d[z - 1][h - x] + x * (b[j][z - 1] - a[i][z - 1]));
					}
				}
			}
			for(int z = 0; z <= k; z++){
				ans = max(ans, d[m][z]);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}