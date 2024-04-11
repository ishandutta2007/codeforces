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

const int inf = (int)1e9;

int a[600][600], d1[600][600], d2[600][600], dd[600][600], sum[600][600];

inline int getsum(int x1, int y1, int x2, int y2){
	return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
}

int main(){
	//freopen("b.in", "r", stdin);
	//freopen("b.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
		}
	}
	int ans = -inf;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			d1[i][j] = a[i][j];
		}
	}
	for(int i = 1; i <= n - 2; i++){
		for(int j = 1; j <= m - 2; j++){
			d2[i][j] = getsum(i, j, i + 2, j + 2) - a[i + 1][j] - a[i + 1][j + 1];
			ans = max(ans, d2[i][j]);
		}
	}
	int k = min(n, m);
	for(int i = 3; i <= k; i += 4){
		if(i + 2 <= k){
			for(int j = 1; j <= n - i - 1; j++){
				for(int z = 1; z <= m - i - 1; z++){
					dd[j][z] = getsum(j, z, j, z + i + 1) + getsum(j + 1, z + i + 1, j + i + 1, z + i + 1);
					dd[j][z] += getsum(j + i + 1, z, j + i + 1, z + i) + getsum(j + 2, z, j + i, z);
					dd[j][z] += a[j + 2][z + 1] + d1[j + 2][z + 2];
					ans = max(ans, dd[j][z]);
				}
			}
			for(int j = 1; j <= n - i - 1; j++){
				for(int z = 1; z <= m - i - 1; z++){
					d1[j][z] = dd[j][z];
				}
			}
		}
		if(i + 4 <= k){
			for(int j = 1; j <= n - i - 3; j++){
				for(int z = 1; z <= m - i - 3; z++){
					dd[j][z] = getsum(j, z, j, z + i + 3) + getsum(j + 1, z + i + 3, j + i + 3, z + i + 3);
					dd[j][z] += getsum(j + i + 3, z, j + i + 3, z + i + 2) + getsum(j + 2, z, j + i + 2, z);
					dd[j][z] += a[j + 2][z + 1] + d2[j + 2][z + 2];
					ans = max(ans, dd[j][z]);
				}
			}
			for(int j = 1; j <= n - i - 3; j++){
				for(int z = 1; z <= m - i - 3; z++){
					d2[j][z] = dd[j][z];
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}