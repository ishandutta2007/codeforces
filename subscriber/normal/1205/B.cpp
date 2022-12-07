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
#define M 1000000007
#define N 411111

#define TASK "1"

using namespace std;

int n;
long long a[N];
vector<int> v[N];
int was[N], dist[N];
int ans = 1e9 + 1;

set<int> ed[N];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 63; j++) if (a[i] & pw(j)) v[j].pb(i);
	}
	for (int i = 0; i < 63; i++) {
		if (v[i].size() > 2) {
			cout << 3 << endl;
			return 0;
		}
		for (int x : v[i]) for (int y : v[i]) ed[x].insert(y);
	}

	int IT = 1;

	for (int i = 0; i < n; i++) {
		IT++;
		queue<int> q;
		q.push(i);
		dist[i] = 0;
		was[i] = IT;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int y : ed[x]) if (was[y] != IT) {
				was[y] = IT;
				dist[y] = dist[x] + 1;
				q.push(y);
			} else if (y != x && dist[y] >= dist[x]) ans = min(ans, dist[x] + dist[y] + 1);
		}
	}
	if (ans > n) ans = -1;
	cout << ans << endl;

	return 0;
}