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

set<pair<int, int> > Q, D;
set<pair<int, pair<int, int> > > C;
set<pair<int, pair<int, int> > >::iterator it;

int n;
pair<int, int > ans[N];

void go(int x, int y) {
	if (Q.find(mp(x, y)) == Q.end()) return;
	if (x > 0 && D.find(mp(x - 1, y)) == D.end()) return;
	if (y > 0 && D.find(mp(x, y - 1)) == D.end()) return;

	Q.erase(mp(x, y));
	C.insert(mp(y - x, mp(x, y)));
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		Q.insert(mp(x, y));
	}
	C.insert(mp(0, mp(0, 0)));
	Q.erase(mp(0, 0));

	for (int i = 0; i < n; i++) {
		int w;
		scanf("%d", &w);

		it = C.lower_bound(mp(w, mp(0, 0)));
		if (it == C.end() || (it->F) != w) {
			puts("NO");
			return 0;
		}

		int x = (*it).S.F;
		int y = (*it).S.S;

		ans[i] = mp(x, y);

		D.insert(mp(x, y));
		C.erase(it);

		go(x + 1, y);
		go(x, y + 1);
	}
	puts("YES");
	for (int i = 0; i < n; i++) printf("%d %d\n", ans[i].F, ans[i].S);
	return 0;
}