#include<bits/stdc++.h>
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
#define N 411111
 
#define TASK "1"
 
using namespace std;

int n, m;
vector<int> v[N];
int deg[N];
int cura[N];
int was[N];
 
int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[y].pb(x);
		deg[x] += 1;
	}
	priority_queue<pair<int, int> > q;
	for (int i = 0; i < n; i++) cura[i] = 1e9 + 1;
	cura[n - 1] = 0;
	q.push(mp(-deg[n - 1], n - 1));

	while (q.size() > 0) {
		int x = q.top().second;
		q.pop();
		if (was[x]) continue;
		was[x] = 1;

		for (int to : v[x]) {
			deg[to]--;
			cura[to] = min(cura[to], cura[x] + deg[to] + 1);
			q.push({-cura[to], to});

		}
	}
	cout << cura[0] << endl;
			
	return 0;
}