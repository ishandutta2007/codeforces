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
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n;
int a[N];

long long s[N];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++) s[i + 1] = s[i] + a[i];

	vector<pair<int, int> > out;
	long long as = 0;
	int ak = 1;
	out.pb(mp(0, 1));
	for (int m = 0; m < n; m++) {
		int l = 0;
		int r = min(m, n - m - 1);

		while (l < r) {
			int mid = (l + r) / 2;

			long long s1 = a[m] + (s[m] - s[m - mid]) + (s[n] - s[n - mid]);
			
			long long s2 = a[m] + (s[m] - s[m - mid - 1]) + (s[n] - s[n - mid - 1]);

			int k1 = 1 + mid * 2;
			int k2 = 3 + mid * 2;

			if (s1 * k2 > s2 * k1) r = mid; else l = mid + 1;
		}
		long long ss = a[m] + (s[m] - s[m - l]) + (s[n] - s[n - l]);
		int k = 1 + l * 2;

		ss -= a[m] * 1ll * k;

		if (ss * ak > as * k) {
			as = ss;
			ak = k;
			out.clear();
			out.pb(mp(m - l, m + 1));	
			out.pb(mp(n - l, n));	
		}
	}
	for (int m = 0; m < n - 1; m++) {
		int l = 0;
		int r = min(m, n - m - 2);

		while (l < r) {
			int mid = (l + r) / 2;

			long long s1 = 2 * a[m] + 2 * a[m + 1] + 2 * (s[m] - s[m - mid]) + 2 * (s[n] - s[n - mid]);
			
			long long s2 = 2 * a[m] + 2 * a[m + 1]+ 2 * (s[m] - s[m - mid - 1]) + 2 * (s[n] - s[n - mid - 1]);

			int k1 = 2 + mid * 2;
			int k2 = 4 + mid * 2;

			if (s1 * k2 > s2 * k1) r = mid; else l = mid + 1;
		}
		long long ss = a[m] * 2 + a[m + 1] * 2 + 2 * (s[m] - s[m - l]) + 2 * (s[n] - s[n - l]);
		int k = 2 + l * 2;
		ss -= (a[m] + a[m + 1]) * 1ll * k;

		k *= 2;

		if (ss * ak > as * k) {
			as = ss;
			ak = k;
			out.clear();
			out.pb(mp(m - l, m + 1));	
			out.pb(mp(n - l, n));	
		}
	}
	vector<int> ans;
	for (int i = 0; i < out.size(); i++) for (int j = out[i].F; j < out[i].S; j++) ans.pb(a[j]);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i + 1 < ans.size()) cout << " "; else cout << endl;
	}

	return 0;
}