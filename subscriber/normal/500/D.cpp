#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n;
int x[N], y[N], c[N];

int sz[N];

vector<int> v[N];

void dfs(int x, int p) {
	sz[x] = 1;
	for (int i = 0; i < v[x].size(); i++) {
		int to = v[x][i];
		if (to == p) continue;
		dfs(to, x);
		sz[x] += sz[to];
	}
	
}

long long val(int i) {
	int t = x[i];
	if (sz[y[i]] < sz[x[i]]) t = y[i];

	return sz[t] * 1ll * (n - sz[t]) * c[i];
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d%d", &x[i], &y[i], &c[i]);
		x[i]--;
		y[i]--;

		v[x[i]].pb(y[i]);
		v[y[i]].pb(x[i]);
	}

	dfs(0, 0);

	long long ans = 0;
	for (int i = 0; i < n - 1; i++) ans += val(i);
	int m;
	cin >> m;

	long long ps = n * 1ll * (n - 1) / 2;
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		ans -= val(a);
		c[a] = b;
		ans += val(a);

		printf("%.10lf\n", ans / 1. / ps * 3); 
	}
	return 0;
}