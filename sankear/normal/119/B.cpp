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

const int inf = (int)1e9;

bool used[200];
int a[200];
int d1[200][200], d2[200][200];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	int q;
	scanf("%d", &q);
	int sz = n / k;
	int ans1 = inf;
	int ans2 = -inf;
	for(int i = 0; i < q; i++){
		int res = 0;
		for(int j = 0; j < sz; j++){
			int num;
			scanf("%d", &num);
			used[num] = true;
			res += a[num];
		}
		ans1 = min(ans1, res);
		ans2 = max(ans2, res);
	}
	int cur = sz * k;
	for(int i = 1; i <= n; i++){
		if(used[i]){
			cur--;
		}
	}
	if(cur >= sz){
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= sz; j++){
				d1[i][j] = inf;
				d2[i][j] = -inf;
			}
		}
		d1[0][0] = 0;
		d2[0][0] = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j <= sz; j++){
				d1[i][j] = d1[i - 1][j];
				d2[i][j] = d2[i - 1][j];
				if(j > 0 && !used[i]){
					d1[i][j] = min(d1[i][j], d1[i - 1][j - 1] + a[i]);
					d2[i][j] = max(d2[i][j], d2[i - 1][j - 1] + a[i]);
				}
			}
		}
		ans1 = min(ans1, d1[n][sz]);
		ans2 = max(ans2, d2[n][sz]);
	}
	double a1 = ((double)ans1) / sz;
	double a2 = ((double)ans2) / sz;
	printf("%.18lf %.18lf\n", a1, a2);
	return 0;
}