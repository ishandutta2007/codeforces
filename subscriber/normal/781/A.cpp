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

int n;
int was[N], q[N], col[N];
int q1, q2;
vector<int> v[N];

int z[N];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	int ans = 0;
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);

		ans = max(ans, (int)v[x].size());
		ans = max(ans, (int)v[y].size());
	}
	ans++;
	cout << ans << endl;
	q[q1++] = 0;
	was[0] = 1;

	z[0] = -1;
	col[0] = 0;
	while (q1 != q2) {
		int x = q[q2++];
		int p = col[x];

		int fr = z[x];
		for (int i = 0; i < v[x].size(); i++) {
			int to = v[x][i];
			if (was[to]) continue;

			p++;
			if (p == ans) p = 0;
			if (p == fr) {
				p++;
				if (p == ans) p = 0;
			}
			col[to] = p;
			z[to] = col[x];
			q[q1++] = to;
			was[to] = 1;
		}
	}
	for (int i = 0; i < n; i++) cout << col[i] + 1 << " ";
	return 0;
}