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

int a[N], s[N], ans[N];

vector<int> z[N];
int n;

int last[N];

int go[N];

void add(int x, int v) {
	while (x <= n) {
		s[x] += v;
		x |= x + 1;
	}
}

int get(int x) {
	int r = 0;
	while (x >= 0) {
		r += s[x];
		x = (x & (x + 1)) - 1;
	}
	return r;
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
	for (int i = 0; i < n; i++) last[i] = n;

	for (int i = n - 1; i >= 0; i--) {
		go[i] = last[a[i]];
		last[a[i]] = i;
	}
	for (int i = 0; i < n; i++) add(last[i], 1);

	for (int i = 1; i <= n; i++) z[0].pb(i);

	for (int g = 0; g < n; g++) {
		for (int i = 0; i < z[g].size(); i++) {
			int k = z[g][i];

			int l = g;
			int r = n;

			while (l < r) {
				int mid = (l + r + 1) / 2;
				if (get(mid) <= k) l = mid; else r = mid - 1;
			}
			ans[k]++;
			z[l + 1].pb(k);
		}
		add(g, -1);
		add(go[g], 1);
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";

	return 0;
}