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

int a[200];
char s[200];
bool usedd[200][200], usedg[200][200];
bool usedf[200][200][200];
int d[200][200], g[200][200];
int f[200][200][200];

void calcd(int l, int r);

void calcf(int l, int r, int k){
	if(usedf[l][r][k]){
		return;
	}
	usedf[l][r][k] = true;
	f[l][r][k] = -inf;
	if(l > r){
		if(k == 0){
			f[l][r][k] = 0;
		}
		return;
	}
	if(k > r - l + 1){
		return;
	}
	if(k == 1){
		for(int i = l; i <= r; i++){
			calcd(l, i - 1);
			calcd(i + 1, r);
			f[l][r][k] = max(f[l][r][k], d[l][i - 1] + d[i + 1][r]);
		}
		return;
	}
	if(l < r && s[l - 1] == s[r - 1]){
		if(k == 2){
			calcd(l + 1, r - 1);
			f[l][r][k] = max(f[l][r][k], d[l + 1][r - 1]);
		}
		else{
			calcf(l + 1, r - 1, k - 2);
			f[l][r][k] = max(f[l][r][k], f[l + 1][r - 1][k - 2]);
		}
	}
	for(int i = l; i < r; i++){
		calcd(l, i);
		calcf(i + 1, r, k);
		f[l][r][k] = max(f[l][r][k], d[l][i] + f[i + 1][r][k]);
		calcf(l, i, k);
		calcd(i + 1, r);
		f[l][r][k] = max(f[l][r][k], f[l][i][k] + d[i + 1][r]);
	}
}

void calcd(int l, int r){
	if(usedd[l][r]){
		return;
	}
	usedd[l][r] = true;
	d[l][r] = -inf;
	if(l > r){
		d[l][r] = 0;
		return;
	}
	for(int i = 1; i <= r - l + 1; i++){
		if(a[i] == -1){
			continue;
		}
		calcf(l, r, i);
		d[l][r] = max(d[l][r], f[l][r][i] + a[i]);
	}
}

void calcg(int l, int r){
	if(usedg[l][r]){
		return;
	}
	usedg[l][r] = true;
	g[l][r] = 0;
	if(l > r){
		return;
	}
	calcd(l, r);
	g[l][r] = max(g[l][r], d[l][r]);
	for(int i = l; i < r; i++){
		calcg(l, i);
		calcg(i + 1, r);
		g[l][r] = max(g[l][r], g[l][i] + g[i + 1][r]);
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	scanf("%s", s);
	calcg(1, n);
	printf("%d\n", g[1][n]);
	return 0;
}