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

int n, m;
vector<int> v[N];
int was[N];
int bad = 0;

void col(int x) {
	for (int i = 0; i < v[x].size(); i++) {
		int to = v[x][i];
		if (was[to] == -1) {
			was[to] = was[x] ^ 1;
			col(to);
		} else {
			if (was[to] == was[x]) bad = 1;
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
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	for (int i = 0; i < n; i++) was[i] = -1;
	for (int i = 0; i < n; i++) if (was[i] == -1) {
		was[i] = 0;
		col(i);
	}
	if (bad) {
		cout << "-1" << endl;
		return 0;
	}
	vector<int> ans;
	for (int i = 0; i < n; i++) if (was[i] == 0) ans.pb(i + 1);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	cout << endl;

	ans.clear();

	for (int i = 0; i < n; i++) if (was[i] == 1) ans.pb(i + 1);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	cout << endl;
	return 0;
}