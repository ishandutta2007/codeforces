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

int n, m;
int ed[555][555];
int bad;
int was[555];

int bb[555];

void go(int x) {
	for (int i = 0; i < n; i++) if (i != x && ed[x][i]) {
		if (bb[i]) continue;
		if (was[i] == 0) {
			was[i] = was[x] ^ 3;
			go(i);
		} else {
			if (was[i] != (was[x] ^ 3)) bad = 1;
		}
	}
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> m;

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) ed[i][j] = 1;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		ed[x][y] = ed[y][x] = 0;		
	}

	for (int i = 0; i < n; i++) {
		bb[i] = 1;
		for (int j = 0; j < n; j++) if (i != j && ed[i][j] == 1) bb[i] = 0;
	}

	bad = 0;
	for (int i = 0; i < n; i++) if (!was[i] && !bb[i]) {
		was[i] = 1;
		go(i);
		
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (i != j) {
		if (bb[i] || bb[j]) continue;
		int no = 0;
		if (was[i] == 1 && was[j] == 2 || was[i] == 2 && was[j] == 1) no = 1;
		if (ed[i][j] != no) bad = 1;

	}
	if (bad) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	for (int i = 0; i < n; i++) {
		if (bb[i]) cout << 'b'; else 

		cout << ((was[i] == 1) ? 'a' : 'c');
	}
	cout << endl;

	return 0;
}