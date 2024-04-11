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
#define N 322000

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, k;
vector<int> pe[N];
vector<pair<int, int> > vs[N];

vector<pair<int, int> > v[N];

int ok[N], ans[N], take[N];

int used[N];

int match(int x) {
	ok[x] = 1;
	int r = 0;
	for (int i = 0; i < v[x].size(); i++) {
		if (used[v[x][i].S]) continue;
		used[v[x][i].S] = 1;


		int to = v[x][i].F;
		if (ok[to]) {
			r = 1;
			take[v[x][i].S] = x;
			break;
		}

		int t = match(to);
		if (t == 1) {
			r = 1;
			take[v[x][i].S] = x;
			break;
		}
		take[v[x][i].S] = to;
	}
	return r;
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int kk;
		scanf("%d", &kk);
		pe[i].resize(kk);
		for (int j = 0; j < kk; j++) {
			scanf("%d", &pe[i][j]);

			vs[abs(pe[i][j])].pb(mp(i, pe[i][j] / abs(pe[i][j])));
		}			
	}
	for (int i = 1; i <= k; i++) {
		if (vs[i].size() == 0) continue;

		if (vs[i].size() == 1) {
			ans[i] = vs[i][0].S;

			ok[abs(vs[i][0].F)] = 1;
			continue;
		}
		if (vs[i][0].S == vs[i][1].S) {
			ans[i] = vs[i][0].S;

			ok[abs(vs[i][0].F)] = 1;
			ok[abs(vs[i][1].F)] = 1;
		} else {
			int x = abs(vs[i][0].F);
			int y = abs(vs[i][1].F);

			v[x].pb(mp(y, i));
			v[y].pb(mp(x, i));
		}
	}
	for (int i = 1; i <= k; i++) take[i] = -1;
	for (int i = 0; i < n; i++) if (!ok[i]) {
		int h = match(i);
		if (h == 0) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for (int i = 1; i <= k; i++) if (take[i] != -1) {
		for (int j = 0; j < vs[i].size(); j++) if (vs[i][j].F == take[i]) {
			ans[i] = vs[i][j].S;
		}	
	}
	for (int i = 1; i <= k; i++) {
		if (ans[i] == -1) ans[i] = 0;
		printf("%d", ans[i]);
	}
	puts("");
	return 0;
}