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

char a[300][300], val[300][300], nval[300][300];

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d %d\n", &n, &k);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%c", &a[i][j]);
		}
		scanf("\n");
	}
	int sz = 1;
	val[0][0] = '.';
	for(int i = 0; i < k; i++){
		int nsz = sz * n;
		for(int j = 0; j < nsz; j++){
			for(int z = 0; z < nsz; z++){
				nval[j][z] = '.';
			}
		}
		for(int j = 0; j < sz; j++){
			for(int z = 0; z < sz; z++){
				if(val[j][z] == '.'){
					for(int h = 0; h < n; h++){
						for(int t = 0; t < n; t++){
							nval[j * n + h][z * n + t] = a[h][t];
						}
					}
				}
				else{
					for(int h = 0; h < n; h++){
						for(int t = 0; t < n; t++){
							nval[j * n + h][z * n + t] = '*';
						}
					}
				}
			}
		}
		sz = nsz;
		for(int j = 0; j < sz; j++){
			for(int z = 0; z < sz; z++){
				val[j][z] = nval[j][z];
			}
		}
	}
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < sz; j++){
			printf("%c", val[i][j]);
		}
		printf("\n");
	}
	return 0;
}