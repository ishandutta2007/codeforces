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
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		unordered_map<int, int> have;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			have[a[i]] += 1;
		}
		int mex = 0;
		int kk = k;
		while (have[mex] > 0 || kk > 0) {
			if (have[mex] == 0) kk--;
			mex++;
			if (mex == n) break;
		}
		if (mex == n) {
			cout << 0<< endl;
			continue;
		}
		unordered_map<int, int> rest;
		for (int i = 0; i < n; i++) if (a[i] > mex) {
			rest[a[i]] += 1;
		}
		vector<int> w;
		for (auto & [key, val] : rest) w.push_back(val);
		sort(w.begin(), w.end());
		int ans = w.size();
		for (int x : w) if (x <= k) {
			k -= x;
			ans--;
		}
		cout << ans << endl;

	}			
	return 0;
}