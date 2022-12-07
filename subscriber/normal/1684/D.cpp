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
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];

			a[i] = -a[i] + (n - i - 1);
		}
		sort(a.begin(), a.end());
		for (int i = 0; i < k; i++) sum += a[i];
		sum -= k * 1ll * (k - 1) / 2;
		cout << sum << endl;
	}		
	return 0;
}