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
map<pair<long long, long long>, long long> ma;

int pre(long long x, long long y) {
	while (y >= 1) {
		if (y == x) return 1;
		y /= 2;
	}
	return 0;
	
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int t;
		long long x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			int w;
			cin >> w;

			while (!pre(x, y)) {
				ma[mp(x / 2, x)] += w;
				x /= 2;
			}
			while (x != y) {
				ma[mp(y / 2, y)] += w;
				y /= 2;
			}
		} else {
			long long ans = 0;
			while (!pre(x, y)) {
				ans += ma[mp(x / 2, x)];
				x /= 2;
			}
			while (x != y) {
				ans += ma[mp(y / 2, y)];
				y /= 2;
			}
			cout << ans << endl;
		}
		
	}

	return 0;
}