#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex <double> tc;

const int mp = (int)1e8;

int d[101][101][11][11], dd[101][101][11][11];

inline void add(int &a, int b){
	a += b;
	while(a >= mp){
		a -= mp;
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  int n1, n2, k1, k2;
	scanf("%d %d %d %d", &n1, &n2, &k1, &k2);
	d[1][0][1][0] = 1;
	d[0][1][0][1] = 1;
	for(int i = 1; i < n1 + n2; i++){
		for(int j = 0; j <= n1; j++){
			for(int z = 0; z <= n2; z++){
				for(int h = 0; h <= k1; h++){
					for(int t = 0; t <= k2; t++){
						dd[j][z][h][t] = 0;
					}
				}
			}
		}
		for(int j = 0; j <= n1; j++){
			for(int z = 0; z <= n2; z++){
				for(int h = 0; h <= k1; h++){
					for(int t = 0; t <= k2; t++){
						if(d[j][z][h][t] == 0){
							continue;
						}
						if(j < n1 && h < k1){
							add(dd[j + 1][z][h + 1][0], d[j][z][h][t]);
						}
						if(z < n2 && t < k2){
							add(dd[j][z + 1][0][t + 1], d[j][z][h][t]);
						}
					}
				}
			}
		}
		for(int j = 0; j <= n1; j++){
			for(int z = 0; z <= n2; z++){
				for(int h = 0; h <= k1; h++){
					for(int t = 0; t <= k2; t++){
						d[j][z][h][t] = dd[j][z][h][t];
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= k1; i++){
		for(int j = 0; j <= k2; j++){
			add(ans, d[n1][n2][i][j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}