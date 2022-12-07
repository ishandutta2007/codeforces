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
#define N 611111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n;
int p[N], sz[N], ans[N];
pair<int, int> q[N];

int get(int x) {
	if (p[x] == x) return x;
	return p[x] = get(p[x]);
}

void unite(int x, int y) {
	if (x < 0 || x >= n) return;
	if (y < 0 || y >= n) return;
	if (p[x] == -1 || p[y] == -1) return;
	x = get(x);
	y = get(y);
	sz[x] += sz[y];
	p[y] = x;
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &q[i].F);
		q[i].S = i;
	}
	sort(q, q + n);

	for (int i = 0; i < n; i++) p[i] = -1, sz[i] = 1;

	for (int i = n - 1; i >= 0; i--) {
		int id = q[i].S;
		p[id] = id;
		unite(id, id - 1);
		unite(id, id + 1);

		ans[sz[id]] = max(ans[sz[id]], q[i].F);
	}
	for (int i = n - 1; i >= 1; i--) ans[i] = max(ans[i], ans[i + 1]);
	for (int i = 1; i <= n; i++) {
		printf("%d", ans[i]);
		if (i == n) puts(""); else putchar(' ');
	}

	return 0;
}