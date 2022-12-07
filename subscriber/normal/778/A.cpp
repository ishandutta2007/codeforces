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

string a, b;
int p[N];
int bad[N];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> a >> b;
	int n = a.size();
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}
	int l = 0;
	int r = n - 1;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		for (int i = 0; i < n; i++) bad[i] = 0;
		for (int i = 0; i < mid; i++) bad[p[i]] = 1;

		string z = "";
		for (int i = 0; i < n; i++) if (!bad[i]) z.pb(a[i]);


		int bad = 0;
		int u = 0;
		for (int i = 0; i < b.size(); i++) {
			while (u < z.size() && b[i] != z[u]) u++;
			if (u == z.size()) {	
				bad = 1;
				break;
			}
			u++;
		}
		if (bad) r = mid - 1; else l = mid;
	}
	cout << l << endl;
	return 0;
}