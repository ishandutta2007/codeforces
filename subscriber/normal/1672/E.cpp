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

const int MAXL = 2000;
 
int main(){
	//#ifdef home
	//	freopen(TASK".in","r",stdin);	
	//	freopen(TASK".out","w",stdout);
	//#endif
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int l = n;
	int r = n * (MAXL + 1);
	while (l < r) {
		int mid = (l + r) / 2;
		cout << "? " << mid << endl;
		int x;
		cin >> x;
		if (x == 1) r = mid; else l = mid + 1;
	}
	int maxr = l;
	/*l = 1;
	r = MAXL;
	while (l < r) {
		int mid = (l + r) / 2;
		cout << "? " << mid << endl;
		int x;
		cin >> x;
		if (x == 0) l = mid + 1; else r = mid;
	}
	int maxe = l;*/
	set<int> s;
	s.insert(maxr);
	s.insert(1);
	for (int i = maxr - n; i <= maxr; i++) {
		int opt = maxr - i;
		for (int r = opt + 1; r * r <= i; r++) if (i % r == 0) {
			s.insert(i / r);
			s.insert(r);
		}
	}
	int ans = 1e9;
	for (int x : s) if ((x + 1) * 1ll* n >= maxr) {
		cout << "? " << x << endl;
		int w;
		cin >> w;
		if (w > 0) ans = min(ans, w * x);
	}
	cout << "! " << ans << endl;
		
	return 0;
}