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
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, m;

vector<int> e[5555];
int f[5555], q[5555];

int good[333][333];

bool rec(int x) {
	if (f[x]) return 0;
	f[x] = 1;
	for (int i = 0; i < e[x].size(); i++) {
		int to = e[x][i];
		if (q[to] == -1) {
			q[to] = x;
			return 1;
		}
	}
	for (int i = 0; i < e[x].size(); i++) {
		int to = e[x][i];
		if (rec(q[to])) {
			q[to] = x;
			return 1;
		}
	}
	return 0;
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> m;

	vector<pair<int, int> > p1, p2;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		
		for (int j = 2; j < 40000; j++) {
			while (x % j == 0) {
				if (i % 2) p1.pb(mp(j, i)); else p2.pb(mp(j, i));
				x /= j;
			}
		}
		if (x > 1) {
			if (i % 2) p1.pb(mp(x, i)); else p2.pb(mp(x, i));
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		good[x - 1][y - 1] = 1;
		good[y - 1][x - 1] = 1;
	}
	for (int i = 0; i < p1.size(); i++) for (int j = 0; j < p2.size(); j++) {
		if (p1[i].F != p2[j].F) continue;
		if (!good[p1[i].S][p2[j].S]) continue;

		e[i].pb(j);
	}

	for (int i = 0; i < p2.size(); i++) q[i] = -1;

	int ans = 0;
	for (int i = 0; i < p1.size(); i++) {
		for (int j = 0; j < p1.size(); j++) f[j] = 0;
		if (rec(i)) ans++;
	}
	cout << ans << endl;

	return 0;
}