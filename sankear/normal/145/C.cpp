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

const ll mp = (ll)(1e9 + 7);

int a[100100], b[100100], sz[100100];
ll f[100100];
ll d[2000][2000];

inline bool good(int a){
	while(a > 0){
		int look = a % 10;
		if(look != 4 && look != 7){
			return false;
		}
		a /= 10;
	}
	return true;
}

inline ll calc(ll a, ll b){
	ll res = 1;
	while(b > 0){
		if(b % 2 != 0){
			res = (res * a) % mp;
		}
		a = (a * a) % mp;
		b /= 2;
	}
	return res;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	int m = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if(good(a[i])){
			b[m++] = a[i];
		}
	}
	sort(b, b + m);
	m = unique(b, b + m) - b;
	for(int i = 0; i < n; i++){
		if(good(a[i])){
			sz[upper_bound(b, b + m, a[i]) - b - 1]++;
		}
	}
	d[0][0] = 1;
	for(int i = 1; i <= m; i++){
		for(int j = 0; j <= i; j++){
			d[i][j] = d[i - 1][j];
			if(j > 0){
				d[i][j] = (d[i][j] + d[i - 1][j - 1] * sz[i - 1]) % mp;
			}
		}
	}
	f[0] = 1;
	for(int i = 1; i <= n; i++){
		f[i] = (f[i - 1] * i) % mp;
	}
	ll ans = 0;
	int all = 0;
	for(int i = 0; i < m; i++){
		all += sz[i];
	}
	for(int i = 0; i <= min(m, k); i++){
		if(k - i > n - all){
			continue;
		}
		ans = (ans + ((((d[m][i] * f[n - all]) % mp) * calc(f[k - i], mp - 2)) % mp) * calc(f[n - all - k + i], mp - 2)) % mp;
	}
	printf("%lld\n", ans);
	return 0;
}