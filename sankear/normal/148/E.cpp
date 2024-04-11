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

int sz[110];
int a[110][110], sum1[110][110], sum2[110][110], f[110][110];
int d[110][10100];

int main(){
	//freopen("tea.in", "r", stdin);
	//freopen("tea.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &sz[i]);
		for(int j = 0; j < sz[i]; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 1; j <= sz[i]; j++){
			sum1[i][j] = sum1[i][j - 1] + a[i][j - 1];
		}
		for(int j = sz[i]; j > 0; j--){
			sum2[i][j] = sum2[i][j + 1] + a[i][j - 1];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 1; j <= sz[i]; j++){
			f[i][j] = -inf;
		}
		for(int j = 0; j <= sz[i]; j++){
			for(int z = 0; z <= sz[i]; z++){
				if(j + z <= sz[i]){
					f[i][j + z] = max(f[i][j + z], sum1[i][j] + sum2[i][sz[i] - z + 1]);
				}
			}
		}
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			d[i][j] = -inf;
		}
	}
	d[0][0] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m; j++){
			d[i][j] = max(d[i][j], d[i - 1][j]);
			for(int z = 1; z <= min(j, sz[i - 1]); z++){
				d[i][j] = max(d[i][j], d[i - 1][j - z] + f[i - 1][z]);
			}
		}
	}
	printf("%d\n", d[n][m]);
	return 0;
}