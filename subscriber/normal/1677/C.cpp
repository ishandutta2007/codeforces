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
		int a[n];
		int b[n];
		int p[n];
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		for (int i = 0; i < n; i++) p[a[i] - 1] = b[i] - 1;

		vector<int> cy;
		vector<int> was(n, 0);
		for (int i = 0; i < n; i++) if (!was[i]) {
			int x = i;
			int sz = 0;
			while (!was[x]) {
				was[x] = 1;
				sz++;
				x = p[x];
			}
			cy.push_back(sz);
		}
		sort(cy.rbegin(), cy.rend());
		int curn = n;
		long long ans = 0;
		for (int g : cy) {
			int steps = g - g % 2;
			int last = 0;
			for (int i = 0; i < steps; i++) {
				int cur;
				if (i % 2 == 0) cur = 0 + i / 2; else
					cur = curn - 1 - i / 2;
				ans += abs(last - cur);
				last = cur;
			}			
			ans += last;
			curn -= steps;
		}
		cout << ans << endl;
	}	 	 			
	return 0;
}