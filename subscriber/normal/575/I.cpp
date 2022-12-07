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

int n, q;
int S[5055][10111];

int x[N], y[N], len[N], ty[N], dr[N];
int ans[N];

void add(int x, int y, int v) {
	while (x < n) {
		int i = y;
		while (i < n + n) {
			S[x][i] += v;
			i |= (i + 1);
		}
		x |= (x + 1);
	}
}

int sum(int x, int y) {
	int r = 0;
	while (x >= 0) {
		int i = y;
		while (i >= 0) {
			r += S[x][i];
			i = (i & (i + 1)) - 1;
		}
		x = (x & (x + 1)) - 1;
	}
	return r;
}

void goc1(int x, int y, int v) {
	add(n - 1 - x, 2 * n - 1 - y, v);
}

void goc2(int x, int y, int v) {
	add(x, y + n, v);
}

void t1(int x, int y, int len, int v) {
	goc1(x + len, x + y + len, v);
	goc1(x - 1, x + y + len, -v);
}

void t2(int x, int y, int len, int v) {
	goc2(x, y - len - x, v);
	goc2(x + len + 1, y - len - x, -v);
}

void sq(int x, int xx, int y, int yy, int v) {
	add(x, y, v);
	add(xx + 1, y, -v);
	add(x, yy + 1, -v);
	add(xx + 1, yy + 1, v);
}


int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);

	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		scanf("%d", &ty[i]);
		if (ty[i] == 2) {	
			scanf("%d%d", &x[i], &y[i]);
		} else {
			scanf("%d%d%d%d", &dr[i], &x[i], &y[i], &len[i]);
		}
		x[i]--;
		y[i]--;
	}

	for (int i = 0; i < q; i++) {
		if (ty[i] == 2) {
			int X = x[i];
			int XpY = x[i] + y[i];
			ans[i] += sum(n - 1 - X, 2 * n - 1 - XpY);
		}
		if (dr[i] == 1) {
			t1(x[i], y[i], len[i], 1);
		}			
		if (dr[i] == 4) {
			//sq
			t1(x[i] - len[i], y[i] - len[i], len[i] - 1, -1);
		}
	}
	//clear
	for (int i = 0; i < n; i++) memset(S[i], 0, sizeof(int) * (2 * n));
	for (int i = 0; i < q; i++) {
		if (ty[i] == 2) {
			int X = x[i];
			int XpY = y[i] - x[i];

			ans[i] += sum(X, XpY + n);
		}
		if (dr[i] == 2) {
			t2(x[i], y[i], len[i], 1);
		}			
		if (dr[i] == 3) {
			//sq
			t2(x[i] - len[i], y[i] + len[i], len[i] - 1, -1);
		}
	}

	//clear
	for (int i = 0; i < n; i++) memset(S[i], 0, sizeof(int) * (2 * n));
	for (int i = 0; i < q; i++) {
		if (ty[i] == 2) {
			ans[i] += sum(x[i], y[i]);
		}
		if (dr[i] == 1) {
			sq(x[i], x[i] + len[i], 0, y[i] - 1, -1);
		}			
		if (dr[i] == 4) {
			sq(x[i] - len[i], x[i], 0, y[i], 1);

			sq(x[i], x[i], 0, y[i] - len[i] - 1, -1);
		}

		if (dr[i] == 2) {
			sq(x[i], x[i] + len[i], y[i] + 1, n - 1, -1);
		}
		if (dr[i] == 3) {
			sq(x[i] - len[i], x[i], y[i], n - 1, 1);

			sq(x[i], x[i], y[i] + len[i] + 1, n - 1, -1);
		}
	}
	for (int i = 0; i < q; i++) if (ty[i] == 2) printf("%d\n", ans[i]);


	return 0;
}