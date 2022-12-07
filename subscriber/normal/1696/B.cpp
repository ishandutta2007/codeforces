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
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int l = 0;
		int r = n - 1;
		while (l <= r && a[l] == 0) l++;
		while (l <= r && a[r] == 0) r--;
		if (l > r) {
			cout << 0 << endl;
		} else {
			int z = 0;
			for (int i = l; i <= r; i++) if (a[i] == 0) z = 1;
			cout << 1 + z << endl;
		}
	}
			
	return 0;
}