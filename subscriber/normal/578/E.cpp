#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<cassert>
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
#define N 411111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

char s[N];

int cur[N];
vector<int> v[N];
vector<vector<int> > g[2][2];

int k;
int ans[N];

int n, L, R;

void out(int x, int y) {
	for (int i = 0; i < g[x][y].size(); i++) for (int j = 0; j < g[x][y][i].size(); j++) {
		ans[k++] = g[x][y][i][j];
	}
}

void out2(int x, int y, int i) {
	for (int j = 0; j < g[x][y][i].size(); j++) {
		ans[k++] = g[x][y][i][j];
	}
}


int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	gets(s);
	n = strlen(s);
	for (int i = 0; i < n; i++) if (s[i] == 'L') L++; else R++;

			priority_queue<pair<int, int> > Ql, Qr;

			for (int i = 0; i < n; i++) Ql.push(mp(0, i));
			for (int i = 0; i < n; i++) Qr.push(mp(0, n + i));

			for (int i = 0; i < n; i++) {
				if (s[i] == 'L') {
					pair<int, int> t = Ql.top();
					Ql.pop();
					cur[i] = t.S;
					t.F++;
					Qr.push(t);
				} else {
					pair<int, int> t = Qr.top();
					Qr.pop();
					cur[i] = t.S;
					t.F++;
					Ql.push(t);
				}
			}
			for (int i = 0; i < n + n; i++) v[i].clear();
			for (int i = 0; i < n; i++) {
				v[cur[i]].pb(i);
			}
			for (int x = 0; x < 2; x++) for (int y = 0; y < 2; y++) g[x][y].clear();
			for (int i = 0; i < n + n; i++) if (v[i].size() > 0) {
				int x = 0;
				if (s[v[i][0]] == 'R') x = 1;
				int y = 0;
				if (s[v[i].back()] == 'L') y = 1;

				g[x][y].pb(v[i]);
			}
			if (g[0][0].size() > 0 && g[1][1].size() > 0 && g[0][1].size() == 0 && g[1][0].size() == 0) {
				assert(false);
			}
			k = 0;

			if (g[0][1].size() == 0 && g[1][0].size() == 0) {
				out(0, 0);
				out(1, 1);
			} else {
				int st = 0;
				if (g[1][0].size() > g[0][1].size()) st = 1;

				int ps[2];
				ps[0] = ps[1] = 0;

				out(st, st);

				out2(st, 1 - st, ps[st]);
				ps[st]++;
				
				st ^= 1;
				out(st, st);
				while (ps[st] < g[st][1 - st].size()) {
					out2(st, 1 - st, ps[st]);
					ps[st]++;
					st = 1 - st;
				}
			}





			if (g[0][1].size() > 0) {
				out(0, 0);
				out(0, 1);
				out(1, 1);
				out(1, 0);
			} else {
				out(1, 1);
				out(1, 0);
				out(0, 0);
				out(0, 1);
			}
	int zz = 0;
	for (int i = 0; i < n - 1; i++) if (ans[i] > ans[i + 1]) zz++;		

	cout << zz<<endl;
	for (int i = 0; i< n; i++) {
		printf("%d", ans[i] + 1);
		if (i + 1 == n) puts(""); else putchar(' ');
	}
	return 0;
}