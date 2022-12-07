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
int s[N];
pair<int, int> q[N];

void add(int x, int v) {
	while (x < n) {
		s[x] += v;
		x |= x + 1;
	}
}

int get(int x) {
	int r = 0;
	while (x >= 0) {
		r += s[x];
		x = (x & (x + 1)) - 1;
	}
	return r;
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> q[i].F;
		q[i].S = i;
	}
	sort(q, q + n);
	for (int i = 0; i < n; i++) add(i, 1);

	long long ans = 0;
	int x = 0;
	for (int i = 0; i < n; i++) {
		vector<int> ps;
		for (int j = i; j < n; j++) if (q[i].F == q[j].F) {
			ps.pb(q[j].S);
			i = j;
		} else break;

		int fi = 0;
		for (int j = 0; j < ps.size(); j++) if (ps[j] >= x) {
			fi = j;
			break;
		}

		for (int j = 0; j < ps.size(); j++) {

			int y = ps[(fi + j) % ps.size()];

			if (x > y) {
				ans += get(n - 1) - get(x - 1);
				x = 0;
			}
			ans += get(y) - get(x - 1);
			x = y;
			add(x, -1);
		}
	}
	cout << ans << endl;
	return 0;
}