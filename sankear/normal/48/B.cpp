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
#include <queue>

using namespace std;

const int inf = (int)1e9;

int n, m;
int matr[60][60];

inline int solve(int a, int b){
	if(a > n || b > m){
		return inf;
	}
	int ans = inf;
	for(int i = 0; i < n - a + 1; i++){
		for(int j = 0; j < m - b + 1; j++){
			int res = 0;
			for(int z = i; z < i + a; z++){
				for(int h = j; h < j + b; h++){
					res += matr[z][h];
				}
			}
			ans = min(ans, res);
		}
	}
	return ans;
}

int main(){
	//freopen("cobweb.in", "r", stdin);
	//freopen("cobweb.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &matr[i][j]);
		}
	}
	int a, b;
	scanf("%d %d", &a, &b);
	int ans = min(solve(a, b), solve(b, a));
	printf("%d\n", ans);
	return 0;
}