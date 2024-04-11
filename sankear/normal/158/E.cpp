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

const int inft = 86400;
const int inf = (int)1e9;

struct teven{
	int t, d;
};

int n, k;
teven t[4040];
int d[4040][4040];

inline bool check(int x){
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= k; j++){
			if(i == n){
				if(inft - d[i][j] >= x){
					return true;
				}
				continue;
			}
			if(t[i].t - d[i][j] - 1 >= x){
				return true;
			}
		}
	}
	return false;
}

int main(){
	//freopen("divisor.in", "r", stdin);
	//freopen("divisor.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &t[i].t, &t[i].d);
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= k; j++){
			d[i][j] = inf;
		}
	}
	d[0][0] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= k; j++){
			d[i][j] = min(d[i][j], max(d[i - 1][j] + 1, t[i - 1].t) + t[i - 1].d - 1);
			if(j > 0){
				d[i][j] = min(d[i][j], d[i - 1][j - 1]);
			}
		}
	}
	int ans = 0, l = 1, r = inft;
	while(l <= r){
		int mid = (l + r) / 2;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}