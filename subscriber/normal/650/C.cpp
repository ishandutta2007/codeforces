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
#define N 1000111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

vector<int> a[N], ans[N];

vector<int> cur;

int X[N], Y[N];
vector<int> vx[N], vy[N];

int was[N];

pair<int, pair<int, int> > q[N];

int n, m;

void go(int x) {
	if (was[x]) return;
	was[x] = 1;
	cur.pb(x);

	int tx = q[x].S.F;
	int ty = q[x].S.S;

	while (vx[tx].size() > 0) {
		int e = vx[tx].back();
		vx[tx].pop_back();
		go(e);
	}
	while (vy[ty].size() > 0) {
		int e = vy[ty].back();
		vy[ty].pop_back();
		go(e);
	}
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	cin >> n >> m;
	for (int i = 0; i < n; i++) a[i].resize(m);
	for (int i = 0; i < n; i++) ans[i].resize(m);

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		scanf("%d", &a[i][j]);
		q[i * m + j] = mp(a[i][j], mp(i, j));
	}			
	sort(q, q + n * m);
	
	for (int i = 0; i < n * m; ) {
		int j = i;
		while (j < n * m && q[i].F == q[j].F) j++;

		for (int k = i; k < j; k++) {
			vx[q[k].S.F].pb(k);
			vy[q[k].S.S].pb(k);
		}
		for (int k = i; k < j; k++) if (!was[k]) {
			cur.clear();
			go(k);

			int ma = 0;
			for (int l = 0; l < cur.size(); l++) {
				ma = max(ma, X[q[cur[l]].S.F]);
				ma = max(ma, Y[q[cur[l]].S.S]);
			}
			ma++;
			for (int l = 0; l < cur.size(); l++) {
				ans[q[cur[l]].S.F][q[cur[l]].S.S] = ma;
				X[q[cur[l]].S.F] = max(X[q[cur[l]].S.F], ma);
				Y[q[cur[l]].S.S] = max(Y[q[cur[l]].S.S], ma);
			}
		}


		i = j;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d", ans[i][j]);
			if (j + 1 < m) putchar(' '); else puts("");
                }
	}


	return 0;
}