#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long ll;
typedef double R;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

const R PI = acos(-1);
const int MAXN = 4123;
const int MAXK = 80;
const int P = 998244353;

namespace MyCode {


int e[MAXN];
int v[MAXN*2], next[MAXN*2];
int f[MAXN*2][MAXK];
int g[MAXK];
int h[MAXK];
int sum[MAXK];

bool vis[MAXN*2];
int k;

void add(int *f, int *g){
	for(int i = 0; i <= k; i++)
		f[i] = (f[i] + g[i]) % P;
}

void dfs(int i){
	if(vis[i])
		return;
	vis[i] = true;
	memset(f[i], 0, sizeof f[i]);
	f[i][0] = 1;
	for(int j = e[v[i]]; j != -1; j = next[j])
		if(j != (i^1))
			dfs(j);
	memset(g, 0, sizeof g);
	for(int j = e[v[i]]; j != -1; j = next[j])
		if(j != (i^1))
			add(g, f[j]);
	for(int x = 0; x <= k; x++)
		for(int y = 0; y <= k-x-1; y++)
			f[i][x+y+1] = (f[i][x+y+1] + (ll)f[i][x] * g[y]) % P;
}

void process(int n){
	int i, j;

	memset(e, -1, sizeof e);
	memset(vis, 0, sizeof vis);

	for(i = 0; i < n-1; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		v[i*2] = b;
		next[i*2] = e[a];
		e[a] = i*2;
		v[i*2+1] = a;
		next[i*2+1] = e[b];
		e[b] = i*2+1;
	}

	for(i = 0; i < (n-1)*2; i++)
		if(!vis[i])
			dfs(i);

	memset(g, 0, sizeof g);
	for(i = 0; i < n; i++){
		memset(sum, 0, sizeof sum);
		for(j = e[i]; j != -1; j = next[j])
			add(sum, f[j]);
		memset(h, 0, sizeof h);
		h[0] = 1;
		for(int x = 0; x <= k; x++)
			for(int y = 0; y <= k-x-1; y++)
				h[x+y+1] = (h[x+y+1] + (ll)h[x] * sum[y]) % P;
		add(g, h);
	}
}

int inv[MAXK*2];
int frac[MAXK*2], frac1[MAXK*2];

void init(int n){
	int i;
	inv[1] = 1;
	for(i = 2; i <= n; i++)
		inv[i] = P - (ll)inv[P%i] * (P/i) % P;
	frac[0] = frac1[0] = 1;
	for(i = 1; i <= n; i++){
		frac[i] = (ll)frac[i-1] * i % P;
		frac1[i] = (ll)frac1[i-1] * inv[i] % P;
	}
}

int C(int n, int m){
	if(m < 0 || m > n)
		return 0;
	return (ll)frac[n] * frac1[m] % P * frac1[n-m] % P;
}

int a[2][MAXK];

int main(){
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int n1, n2;
	scanf("%d%d%d", &n1, &n2, &k);
	if(k % 2 == 1)
		k = -1;
	else
		k /= 2;
	process(n1);
	for(int i = 0; i <= k; i++)
		a[0][i] = g[i];
	process(n2);
	for(int i = 0; i <= k; i++)
		a[1][i] = g[i];
	int ans = 0;
	if(k >= 0){
		init(k*2);
		for(int i = 0; i <= k; i++)
			ans = (ans + (ll)a[0][i] * a[1][k-i] % P * C(2*k, 2*i)) % P;
	}
	printf("%d\n", ans);
	return 0;
}
}

int main(){
	return MyCode::main();
}