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
		for (int i = 0; i < n; i++) cin >> a[i];

		int l = -1;
		int r = -1;
		for (int i = 0; i + 1 < n; i++) if (a[i] == a[i + 1]) {
			if (l == -1) l = i;
			r = i;
		}
		int ans = 0;
		if (l != r) ans = max(r - l - 1, 1);
		cout << ans << endl;
	}	
	return 0;
}