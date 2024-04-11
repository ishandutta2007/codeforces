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
vector<int> v[N];
int was[N], de[N];

int bad = 0;

void go(int x) {
	was[x] = 1;
	int cnt = 0;
	for (int i = 0; i < v[x].size(); i++) {
		int to = v[x][i];
		if (!de[to]) cnt++;
	}
	if (cnt > 2) bad = 1;

	for (int i = 0; i < v[x].size(); i++) {
		int to = v[x][i];
		if (!de[to] && !was[to]) go(to);
	}
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	for (int i = 0; i < n; i++) if (!de[i] && v[i].size() == 1) {
		int pr = -1;
		int x = i;

		for(;;) {
			de[x] = 1;

			int to = -1;
			for (int j = 0; j < v[x].size(); j++) if (v[x][j] != pr) to = v[x][j];
			if (v[to].size() >= 3) to = -1;

			if (to == -1) break;

			pr = x;
			x = to;
		}
	}
	for (int i = 0; i < n; i++) if (v[i].size() == 3) {
		int x = i;
		int cd = 0;
		for (int j = 0; j < v[x].size(); j++) if (de[v[x][j]] == 1) cd++;
		if (cd == 2) de[i] = 2;
	}

	int z = 0;
	for (int i = 0; i < n; i++) if (!de[i] && !was[i]) {
		z++;
		go(i);
	}
	if (z == 0) {
		puts("Yes");
	} else if (z > 1 || bad) {
		puts("No");
	} else {
		puts("Yes");
	}

	return 0;
}