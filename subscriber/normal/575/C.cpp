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

int n;
int a[2][22][22];

int S, T;
int yy[8888], cs[8888], xx[8888], pp[8888], fl[8888];
int f[8888], d[8888], ww[8888], pr[8888];
int kk;

void ae(int x, int y, int ff, int coco) {
	yy[++kk] = y;
	cs[kk] = coco;
	fl[kk] = ff;
	pp[kk] = xx[x];
 	xx[x] = kk;	

	yy[++kk] = x;
	cs[kk] = -coco;
	fl[kk] = 0;
	pp[kk] = xx[y];
 	xx[y] = kk;	
 	
}

int p[22];

int val(int o) {
			
		S = n + n;
		T = S + 1;
		for (int i = 0; i <= T; i++) xx[i] = 0;
		kk = 1;

		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
			int dd = 0;
			if (o & pw(j)) dd = 1;

			ae(i, j + n, 1, a[dd][i][j]);
		}
		for (int i = 0; i < n; i++) ae(S, i, 1, 0);
		for (int i = 0; i < n; i++) ae(i + n, T, 1, 0);

		for (int i = 0; i <= T; i++) {
			ww[i] = 0;
		}

		int cur = 0;
		for (int it = 0; it < n; it++) {
			for (int i = 0; i <= T; i++) {
				f[i] = 0;
				d[i] = 1e9;
			}
			d[S] = 0;
			for (;;) {
				int mi = 1e9;
				int x = -1;
				for (int i = 0; i <= T; i++) if (!f[i] && d[i] < mi) {
					mi = d[i];
					x = i;
				}
				if (x == -1) break;
				f[x] = 1;
				for (int w = xx[x]; w; w = pp[w]) if (fl[w] > 0) {
					int to = yy[w];
					int dist = d[x] + cs[w] + ww[x] - ww[to];
					if (dist < d[to]) {
						d[to] = dist;
						pr[to] = w;
					}
				}
			}
			int x = T;
			while (x != S) {
				cur += cs[pr[x]];
				fl[pr[x]]--;
				fl[pr[x] ^ 1]++;
				x = yy[pr[x] ^ 1];
			}
			for (int i = 0; i <= T; i++) if (d[i] != 1e9) ww[i] += d[i];
		}
		return 1e6 * n - cur;
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	for (int dd = 0; dd < 2; dd++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		cin >> a[dd][i][j];
		a[dd][i][j] = 1e6 - a[dd][i][j];
	}		

	int ans = 0;
	for (int it = 0; it < 10; it++) {
		for (int i = 0; i < n; i++) p[i] = 0;
		for (int i = 0; i < n / 2; i++) p[i] = 1;
		random_shuffle(p, p + n);
		int o = 0;
		for (int i = 0; i < n; i++) if (p[i]) o += pw(i);

		int s = val(o);
		for (int i = 0; i < 1000; i++) {
			int x = rand() % n;
			int y = rand() % n;			
			if (((o & pw(x)) > 0) && ((o & pw(y)) > 0)) {
				i--;
				continue;
			}
			if (((o & pw(x)) == 0) && ((o & pw(y)) == 0)) {
				i--;
				continue;
			}
			int oo = o ^ pw(x) ^ pw(y);
			int ss = val(oo);
			if (ss > s) {
				o = oo;
				s = ss;
			}
		}
		ans = max(ans, s);
	}


	cout << ans << endl;
	return 0;
}