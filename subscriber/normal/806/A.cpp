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

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int x,y, p, q;
		cin >> x >> y >> p >> q;

		int l = 0;
		int r = 1e9 + 10;
		int ok = 0;
		while (l < r) {
			int mid  = (l + r) / 2;

			long long pp = p * 1ll * mid;
			long long qq = q * 1ll * mid;

			long long ne = qq - pp;

			if (pp >= x && ne >= y - x) {
				ok = 1;
				r = mid;
			} else l = mid + 1;
		}
		if (!ok) cout << -1 << endl; else cout << l * 1ll * q - y  << endl;
	}
	return 0;
}