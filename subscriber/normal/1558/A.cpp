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

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif
	int ts;
	cin >> ts;
	while (ts--) {
		int a, b;
		cin >> a >> b;
		vector<int> ans;
		for (int e = 0; e < 2; e++) {
			int aa = (a + b + e) / 2;
			int bb = a + b - aa;
			
			
			int d = abs(aa - a);
			for (int i = 0; i < (a + b); i++) {
				if (a > aa) {
					if (d + i > bb) break;
					if (i > aa) break;
				} else {
					if (d + i > aa) break;
					if (i > bb) break;
				}
				ans.pb(d + i * 2);
			}
		}
		sort(ans.begin(), ans.end());
		ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
		cout << ans.size() <<endl;
		for (int x : ans) cout << x << " ";
		cout << endl;
	}
	return 0;
}