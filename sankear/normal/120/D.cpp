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

int n, m;
bool used[10];
int val[10], cur[10];
bool good1[100][100], good2[100][100];
int sum[100][100];

inline int get(int x1, int y1, int x2, int y2){
	return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
}

void gen(int x){
	if(x >= 3){
		for(int i = 1; i < n - 1; i++){
			for(int j = i + 1; j < n; j++){
				int sum1 = get(1, 1, i, m);
				int sum2 = get(i + 1, 1, j, m);
				int sum3 = get(j + 1, 1, n, m);
				if(sum1 == cur[0] && sum2 == cur[1] && sum3 == cur[2]){
					good1[i][j] = true;
				}
			}
		}
		for(int i = 1; i < m - 1; i++){
			for(int j = i + 1; j < m; j++){
				int sum1 = get(1, 1, n, i);
				int sum2 = get(1, i + 1, n, j);
				int sum3 = get(1, j + 1, n, m);
				if(sum1 == cur[0] && sum2 == cur[1] && sum3 == cur[2]){
					good2[i][j] = true;
				}
			}
		}
		return;
	}
	for(int i = 0; i < 3; i++){
		if(!used[i]){
			cur[x] = val[i];
			used[i] = true;
			gen(x + 1);
			used[i] = false;
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
  scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int a;
			scanf("%d", &a);
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a;
		}
	}
	for(int i = 0; i < 3; i++){
		scanf("%d", &val[i]);
	}
	gen(0);
	int ans = 0;
	for(int i = 1; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(good1[i][j]){
				ans++;
			}
		}
	}
	for(int i = 1; i < m - 1; i++){
		for(int j = i + 1; j < m; j++){
			if(good2[i][j]){
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}