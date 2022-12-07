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
#define N 811111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

const int maxn = 200111;

int n, ed;
vector<pair<int, int> > v[N];
int del[N], u[N];
char ans[N];

void go(int x) {	
	while (u[x] < v[x].size()) {
		int id = v[x][u[x]].S;
		if (del[id]) {
			u[x]++;
			continue;
		}

		if (id < n) {
			if (x < maxn) ans[id] = 'b'; else ans[id] = 'r';
		}
		del[id] = 1;
		go(v[x][u[x]].F);
		u[x]++;
	}
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);

		v[x].pb(mp(y + maxn, i));
		v[y + maxn].pb(mp(x, i));
	}
	vector<int> odd1;

	for (int i = 0; i < maxn * 2; i++) if (v[i].size() % 2) odd1.pb(i);

	ed = n;

	for (int i = 0; i < odd1.size(); i += 2) {
		v[odd1[i]].pb(mp(odd1[i + 1], ed));
		v[odd1[i + 1]].pb(mp(odd1[i], ed));
		ed++;
	}
	for (int i = 0; i < maxn * 2; i++) u[i] = 0;

	for (int i = 0; i < maxn * 2; i++) go(i);
	
	puts(ans);	

	return 0;
}