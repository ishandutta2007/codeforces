#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
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
typedef pair<int,int> pt;

int n, q;
pair<int, int> a[N];

int x[N];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);

	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		a[i] = mp(x[i], i);
	}
	sort(a, a + n);

	while (q--) {
		int t, L;
		cin >> t >> L;

		t--;
		t = lower_bound(a, a + n, mp(x[t], t)) - a;

		vector<int> ph;
		ph.pb(t);

		int go = 1;
		
		for(;;) {
			if (go) {
				int l = 0;
				int r = n - 1;
				while (l < r) {
					int mid = (l + r + 1) / 2;
					if (a[mid].F - L > a[t].F) r = mid - 1; else l = mid;
				}
				L -= a[l].F - a[t].F;
				t = l;
				ph.pb(t);
				go ^= 1;
			} else {
				int l = 0;
				int r = n - 1;
				while (l < r) {
					int mid = (l + r) / 2;
					if (a[t].F - L > a[mid].F) l = mid + 1; else r = mid;
				}
				L -= a[t].F - a[l].F;
				t = l;
				ph.pb(t);
				go ^= 1;
			}

			if (ph.size() > 2 && ph[ph.size() - 1] == ph[ph.size() - 2] && ph[ph.size() - 2] == ph[ph.size() - 3]) break;

			if (ph.size() > 2 && ph[ph.size() - 1] == ph[ph.size() - 3]) {
//				cout << ph[ph.size() - 1] << " " << ph[ph.size() - 3] << endl;
				L %= 2 * abs(a[ph[ph.size() - 1]].F - a[ph[ph.size() - 2]].F);
			}				
		}
		cout << a[t].S + 1 << endl;
	}

	return 0;
}