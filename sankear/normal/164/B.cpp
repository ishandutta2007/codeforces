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

#define pb push_back

const int maxn = (int)2e6 + 200;
const int size = (int)1e6;

int a[maxn], b[maxn], pos[maxn], val[maxn], sum[maxn], d[maxn];

inline int getsum(int l, int r){
	return sum[r] - (l > 0 ? sum[l - 1] : 0);
}

int main(){
	//freopen("bibliophile.in", "r", stdin);
	//freopen("bibliophile.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < m; i++){
		scanf("%d", &b[i]);
	}
	for(int i = 1; i <= size; i++){
		pos[i] = -1;
	}
	for(int i = 0; i < m; i++){
		pos[b[i]] = i;
	}
	for(int i = 0; i < n; i++){
		val[i] = val[i + n] = pos[a[i]];
	}
	for(int i = 0; i < 2 * n; i++){
		sum[i] = (i > 0 ? sum[i - 1] : 0) + (val[i] != -1);
	}
	for(int i = 2 * n - 1; i >= 0; i--){
		d[i] = 1;
		if(i < 2 * n - 1 && val[i] < val[i + 1]){
			d[i] = d[i + 1] + 1;
		}
	}
	int ans = 0;
	for(int i = 0; i < 2 * n; i++){
		while(i + ans < 2 * n && getsum(i, i + ans) == ans + 1){
			if(i + d[i] - 1 >= i + ans){
				ans++;
				continue;
			}
			if(i + d[i] + d[i + d[i]] - 1 >= i + ans && val[i + ans] < val[i]){
				ans++;
				continue;
			}
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}