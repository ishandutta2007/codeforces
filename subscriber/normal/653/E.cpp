#include<stdio.h>
#include<iostream>
#include<unordered_set>
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

int n, m, k;
vector<int> cur;

unordered_set<long long> bad;

unordered_set<int> was;

void err() {
	cout << "impossible" << endl;
	exit(0);
}

void go(int x) {
	cur.pb(x);

	vector<int> g;

	for (auto it = was.begin(); it != was.end(); it++) if (bad.count(x * 1000000ll + (*it)) == 0) g.pb(*it);
	for (int i = 0; i < g.size(); i++) was.erase(g[i]);

	for (int i = 0; i < g.size(); i++) go(g[i]);
	
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		bad.insert(x * 1000000ll + y);
		bad.insert(y * 1000000ll + x);
	}

	for (int i = 1; i < n; i++) was.insert(i);

	vector<vector<int> > comps;
	
	for (int i = 1; i < n; i++) if (was.count(i)) {
		cur.clear();
		was.erase(i);
		go(i);

		comps.pb(cur);
	} 
/*	for (int i = 0; i < comps.size(); i++) {
		for (int j = 0; j < comps[i].size(); j++) cout << comps[i][j] << " ";
		cout << endl;
	}*/
	int sum = 0;

	for (int i = 0; i < comps.size(); i++) {
		int cnt = 0;

		for (int j = 0; j < comps[i].size(); j++) if (bad.count(comps[i][j]) == 0) cnt++;
		if (cnt == 0) err();
		sum += cnt;
	}

	if (k < comps.size() || k > sum) err();
	cout << "possible" << endl;


	return 0;
}