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
	ios::sync_with_stdio(false);
	long long p, k;
	cin >> p >> k;

	vector<int> ans;
	int o = 0;
	while (p != 0) {
		if (o == 0) {
			ans.pb(p % k);
			p /= k;
		} else {
			int g = k - (p % k);
			if (g == k) {
				ans.pb(0);
				p /= k;
			} else {
				ans.pb(g);
				p = (p + g) / k;
			}
		}
		o ^= 1;
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	return 0;
}