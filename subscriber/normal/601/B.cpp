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
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, k;
int a[N];

pair<int, int> d[22][N];
int gg[N];

long long sol(int x, int y) {
	if (y - x <= 0) return 0;
	int w = gg[y - x];
	int z = max(d[w][x], d[w][(y - 1) - pw(w) + 1]).S;

	long long ret = abs(a[z] - a[z + 1]) * 1ll * (z - x + 1) * (y - z);
	ret += sol(x, z);
	ret += sol(z + 1, y);

	return ret;
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n - 1; i++) d[0][i] = mp(abs(a[i] - a[i + 1]), i);

	gg[1] = 0;
	for (int i = 2; i <= n; i++) gg[i] = gg[i / 2] + 1;
	
	for (int i = 1; i <= gg[n]; i++) for (int j = 0; j + pw(i) <= n - 1; j++) d[i][j] = max(d[i - 1][j], d[i - 1][j + pw(i - 1)]);

	for (int i = 0; i < k; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		cout << sol(x, y) << endl;
	}
	return 0;
}