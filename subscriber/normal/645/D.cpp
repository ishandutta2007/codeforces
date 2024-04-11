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
vector<int> v[N];

int was[N];

int x[N], y[N];

vector<int> order;

int u[N];

void go(int x) {
	if (was[x]) return;
	was[x] = 1;
	for (int i = 0; i < v[x].size(); i++) go(v[x][i]);
	order.pb(x);
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> x[i] >> y[i];
		x[i]--;
		y[i]--;
	}		
	int l = 1;
	int r = m + 1;

	while (l < r) {
		int mid = (l + r) / 2;

		for (int i = 0; i < n; i++) v[i].clear();
		for (int i = 0; i < mid; i++) v[x[i]].pb(y[i]);

		for (int i = 0; i < n; i++) was[i] = 0;
		order.clear();
		for (int i = 0; i <n; i++) if (!was[i]) go(i);
		reverse(order.begin(), order.end());

/*		cout << mid << endl;
		for (int i = 0; i < n; i++) cout << order[i] << " ";
		cout << endl;*/

		for (int i = 0; i < n; i++) u[order[i]] = i;

		int nei = 0;
		for (int i = 0; i < mid; i++) if (u[x[i]] + 1 == u[y[i]]) nei++;

		if (nei == n - 1) r = mid; else l = mid + 1;
	}
	if (l == m + 1) l = -1;
	cout << l << endl;


	return 0;
}