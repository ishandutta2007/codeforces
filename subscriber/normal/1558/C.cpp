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


int p[N];

void swap(int n) {
	for (int i = 0; i < n / 2; i++) swap(p[i], p[n - 1 - i]);
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif
	int ts;
	cin >> ts;
	while (ts--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> p[i], p[i]--;
		int bad = 0;
		for (int i = 0; i < n; i++) if (i % 2 != p[i] % 2) bad = 1;
		if (bad) {
			cout << -1 << endl;
			continue;
		}
		vector<int> ans;
		for (int k = n - 1; k > 0; k -= 2) {
			int pn = -1;
			int px = -1;
			for (int i = 0; i <= k; i++) if (p[i] == k) pn = i; else if (p[i] == k - 1) px = i;
			
			ans.pb(pn + 1);
			swap(pn + 1);
			for (int i = 0; i <= k; i++) if (p[i] == k) pn = i; else if (p[i] == k - 1) px = i;
			
			ans.pb(px);
			swap(px);
			for (int i = 0; i <= k; i++) if (p[i] == k) pn = i; else if (p[i] == k - 1) px = i;
			
			ans.pb(px + 2);
			swap(px + 2);
			
			ans.pb(3);
			swap(3);
			
			ans.pb(k + 1);
			swap(k + 1);			
		}
		cout << ans.size() << endl;
		for (int x : ans) cout << x << " ";
		cout << endl;
		
	}
	return 0;
}