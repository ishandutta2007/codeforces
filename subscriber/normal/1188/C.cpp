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
#define M 998244353
#define N 411111

#define TASK "1"

using namespace std;

int n, k;
long long dp[N], dp2[N];
int p[N];

map<int, int> ccc;

int cc[N];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i], ccc[a[i]]++;
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());

	n = a.size();
	for (int i = 0; i < n; i++) cc[i] = ccc[a[i]];

	vector<int> tots;
	for (int j = 0; j < n; j++) p[j] = j;

	for (int d = 1; d <= 100020; d++) {
		if (d * (k - 1) > 300000) {
			tots.pb(0);
			continue;
		}
		for (int j = 0; j < n; j++) {
			while (p[j] < n && a[p[j]] - a[j] < d) p[j]++;
		}
		for (int j = 0; j < n; j++) dp[j] = cc[j];
		int first = 0;

		for (int it = 1; it < k; it++) {
			for (int j = 0; j <= n; j++) dp2[j] = 0;
			for (int j = 0; j < n; j++) dp2[p[j]] += dp[j];
			long long cum = 0;
			for (int j = 0; j < n; j++) {
				cum = (cum + dp2[j]) % M;
				dp[j] = cum * cc[j] % M;
			}
			int nfirst = -1;
			for (int j = 0; j < n; j++) if (dp[j] > 0) {
				nfirst = j;
				break;
			}
			if (nfirst == -1) break;
			first = nfirst;
		}
		int tot = 0;
		for (int j = 0; j < n; j++) tot = (tot + dp[j]) % M;
		if (d * (k - 1) > 200000) assert(tot == 0);
		tots.pb(tot);
//		if (d < 100) cout << d << " " << tot << endl;
	}
	long long ans = 0;

	for (int i = 0; i < (int)tots.size() - 1; i++) ans = (ans + (tots[i] - tots[i + 1] + M) * 1ll * (i + 1)) % M;
	cout << ans << endl;


	return 0;
}