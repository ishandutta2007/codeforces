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
int a[N], p[N], b[N];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i];
	for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
	for (int i = 0; i < n; i++) cin >> b[i], b[i]--;

	multiset<int> q[3][3];

	for (int i = 0; i < n; i++) q[a[i]][b[i]].insert(p[i]);

	int qq;
	cin >> qq;
	while (qq--) {
		int mi = 1e9 + 1;
		int x;
		cin >> x;
		x--;

		int ii, jj;
		for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) if (i == x || j == x) {
			auto it = q[i][j].begin();
			if (it != q[i][j].end()) {
				int cost = *it;
				if (cost < mi) {
					mi = cost;
					ii = i;
					jj = j;
				}
			}
		}
		if (mi > 1e9) mi = -1; else {
			q[ii][jj].erase(q[ii][jj].begin());
		}
		cout << mi << " ";

	}

	return 0;
}