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
		vector<int> a(n);
		long long sum = 0;
		int bad = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		while (n > 1 && a[n - 1] == 0) n--;
		if (n == 1) {
			if (a[0]  == 0) cout << "Yes\n"; else cout << "No\n";
			continue;
		}

		if (a[0] < 1 || a[n - 1] > 0) bad = 1;
		a[0]--;
		a[n - 1]++;
		for (int i = 0; i < n; i++) {
			sum += a[i];
			if (sum < 0) bad = 1;
		}
		if (sum != 0) bad = 1;
		if (bad) cout << "No\n"; else cout << "Yes\n";
	}		
	return 0;
}