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

int n, A, B;

int be[N];

int solve(vector<pair<int, int> > a, int c) {
	int ret = -1e9;
	if (a.size() == 0) return ret;
	sort(a.begin(), a.end());
	be[0] = a[0].S;
	for (int i = 0; i < a.size(); i++) {
		int cost = a[i].F;

		int l = -1;
		int r = i - 1;
		while (l < r) {
			int mid = (l + r + 1) / 2;
			if (a[mid].F <= c - cost) l = mid; else r = mid - 1;
		}
		if (l != -1) ret = max(ret, a[i].S + be[l]);
		be[i] = max(be[i - 1], a[i].S);
	}
	return ret;
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> A >> B;
	vector<pair<int, int> > a, b;
	int a1 = -1e9, a2 = -1e9;

	for (int i = 0; i < n; i++) {
		int x, y;
		char c;
		cin >> x >> y >> c;

		if (c == 'C') {
			if (y <= A) a1 = max(a1, x);
			a.pb(mp(y, x));
		} else {
			if (y <= B) a2 = max(a2, x);
			b.pb(mp(y, x));
		}
	}
	int ans = a1 + a2;

	ans = max(ans, solve(a, A));
	ans = max(ans, solve(b, B));
	if (ans < 0) ans = 0;
	cout << ans << endl;
	return 0;
}