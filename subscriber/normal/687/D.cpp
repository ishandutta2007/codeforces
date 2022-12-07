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
#define N 1000111

#define TASK "1"

using namespace std;

int n, m, Q;
pair<pair<int,int>, pair<int, int> > q[N];

int p[1111];
int d[1111];
vector<int> v[1111];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	cin >> n >> m >> Q;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &q[i].S.F, &q[i].S.S, &q[i].F.F);
		q[i].S.F--;
		q[i].S.S--;
		q[i].F.S = i;
	}
	sort(q, q + m);
	reverse(q, q + m);

	for (int i = 0; i < Q; i++) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;

		for (int i = 0; i < n; i++) v[i].clear();
		for (int i = 0; i < n; i++) {
			p[i] = i;
			d[i] = 0;
			v[i].pb(i);
		}			

		int ans = -1;
		for (int i = 0; i < m; i++) if (q[i].F.S >= l && q[i].F.S <= r) {
			int x = q[i].S.F;
			int y = q[i].S.S;
			if (p[x] == p[y]) {
				if (d[x] == d[y]) {
					ans = q[i].F.F;
					break;
				}
				continue;
			}					
			
			int we = 1 ^ d[x] ^ d[y];

			if (v[p[x]].size() > v[p[y]].size()) swap(x, y);

			int c = p[x];

			for (int j = 0; j < v[c].size(); j++) {
				int t = v[c][j];
				d[t] = d[t] ^ we;
				p[t] = p[y];
				v[p[y]].pb(t);
			}

		}
		cout << ans << endl;
	}

	return 0;
}