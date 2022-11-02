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
const ll infval = (ll)1e18;

struct tp{
	int a, b;
};

int n, m;
int b[300], cur[300];
int a[300][300];
ll d[300][300];
tp p[300];

bool operator < (const tp &a, const tp &b){
	if(a.a != b.a){
		return a.a < b.a;
	}
	return a.b < b.b;
}

inline ll calc(){
	for(int i = 0; i <= n + m - 1; i++){
		for(int j = 0; j <= n + m - 1; j++){
			d[i][j] = 0;
		}
	}
	d[0][0] = 1;
	for(int i = 1; i <= n + m - 1; i++){
		for(int j = 0; j <= n + m - 1; j++){
			if(cur[i - 1] != 1){
				d[i][j] = min(d[i][j] + d[i - 1][j + 1], infval);
			}
			if(j > 0 && cur[i - 1] != 2){
				d[i][j] = min(d[i][j] + d[i - 1][j - 1], infval);
			}
		}
	}
	return d[n + m - 1][0];
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll k;
	scanf("%d %d %I64d", &n, &m, &k);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 0; i < n + m - 1; i++){
		b[i] = inf;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			b[i + j] = min(b[i + j], a[i][j]);
		}
	}
	for(int i = 0; i < n + m - 1; i++){
		p[i].a = b[i];
		p[i].b = i;
	}
	sort(p, p + n + m - 1);
	for(int i = 0; i < n + m - 1; i++){
		cur[p[i].b] = 1;
		ll all = calc();
		if(all < k){
			cur[p[i].b] = 2;
			k -= all;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(cur[i + j] == 1){
				printf("(");
			}
			else{
				printf(")");
			}
		}
		printf("\n");
	}
	return 0;
}