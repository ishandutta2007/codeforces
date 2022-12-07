#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
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
#define N 1000111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n;
long long A, B;

int a[N];
long long pref[N], suff[N];

vector<int> e;

void add(int x) {
	for (int i = 2; i * i <= x; i++) if (x % i == 0) {
		e.pb(i);
		while (x % i == 0) x /= i;
	}
	if (x > 1) e.pb(x);
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);

	cin >> n >> A >> B;
	for (int i = 0; i < n; i++) cin >> a[i];

	add(a[0]);
	add(a[0] - 1);
	add(a[0] + 1);

	add(a[n - 1]);
	add(a[n - 1] + 1);
	add(a[n - 1] - 1);

	sort(e.begin(), e.end());

	long long ans = 1e18 + 1;

	for (int i = 0; i < e.size(); i++) {
		if (i > 0 && e[i] == e[i - 1]) continue;

		int s = e[i];

		for (int i = 0; i < n; i++) {
			pref[i] = 1e18 + 1;
			if (a[i] % s == 0) pref[i] = 0; else if ((a[i] + 1) % s == 0 || (a[i] - 1) % s == 0) pref[i] = B;
			if (i > 0) pref[i] += pref[i - 1];
			pref[i] = min(pref[i], (long long)( 1e18 + 1));

			ans = min(ans, pref[i] + (n - 1 - i) * A);
		}
		for (int i = 0; i < n; i++) pref[i] -= A * (i + 1);
		for (int i = 1; i < n; i++) pref[i] = min(pref[i], pref[i - 1]);

		for (int i = n - 1; i >= 0; i--) {
			suff[i] = 1e18 + 1;
			if (a[i] % s == 0) suff[i] = 0; else if ((a[i] + 1) % s == 0 || (a[i] - 1) % s == 0) suff[i] = B;
			if (i + 1 < n) suff[i] += suff[i + 1];

			suff[i] = min(suff[i], (long long)( 1e18 + 1));

			ans = min(ans, suff[i] + A * i);

			if (i == 0) ans = min(ans, suff[i]); else {
				
				long long cost = suff[i] + i * A + pref[i - 1];
				ans = min(ans, cost);
			}				
		}
	}
	cout << ans << endl;



	return 0;
}