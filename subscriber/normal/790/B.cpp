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
#define N 211111

#define TASK "1"

using namespace std;

int n, k;
vector<int> v[N];

int sz[N];
long long full[N];

long long ans = 0;

vector<int> go(int x, int p) {
	vector<int> ret;
	for (int i = 0; i < k; i++) ret.pb(0);
	ret[0]++;

	sz[x] = 1;
	full[x] = 0;

	for (int i = 0; i < v[x].size(); i++) {
		int to = v[x][i];
		if (to == p) continue;

		vector<int> e = go(to, x);

		vector<int> ee(k, 0);

		for (int b = 0; b < k; b++) {
			if (b < k - 1) {
				ee[b + 1] += e[b];
			} else {
				ee[0] += e[b];
				full[to] += e[b];
			}
		}
		ans += sz[x] * 1ll * full[to];
		ans += sz[to] * 1ll * full[x];


		for (int a = 0; a < k; a++) for (int b = 0; b < k; b++) {
			ans += (a + b + k - 1) / k * 1ll * ret[a] * ee[b];
		}
		full[x] += full[to];
		sz[x] += sz[to];

		for (int a = 0; a < k; a++) ret[a] += ee[a];
	}
	return ret;
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	go(0, 0);
	cout << ans << endl;
	return 0;
}