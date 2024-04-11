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

vector<int> v[N];

set<pair<int,int> > s[N];


 
int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	int ts;
	cin >> ts;
	while (ts--) {
		int n;
		cin >> n;
		vector<int> p(n);
		for (int i = 0; i < n; i++) v[i].clear();
		p[0] = -1;
		for (int i = 1; i < n; i++) {
			cin >> p[i];
			p[i]--;
			v[p[i]].push_back(i);
		}
		vector<int> l(n);
		vector<int> r(n);
		for (int i = 0; i < n; i++) cin >> l[i] >> r[i];

		int ans = 0;
		function<int(int)> f;
		f = [&](int x) {
			if (v[x].size() == 0) {
				ans++;
				return r[x];
			}
			long long sr = 0;
			for (int to : v[x]) sr += f(to);
			if (l[x] <= sr) return (int)min(sr, (long long)r[x]);
			ans++;
			return r[x];
		};
		f(0);
		cout << ans << endl;

	}	
	return 0;
}