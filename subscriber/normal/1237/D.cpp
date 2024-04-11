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

int n;
int a[N], lg[N], ans[N];
int f[22][N];
int t[N];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], a[i + n] = a[i];

	lg[1] = 0;
	for (int i = 2; i <= n + n; i++) lg[i] = lg[i / 2] + 1;


	for (int i = 0; i < n + n; i++) f[0][i] = a[i];
	for (int i = 1; i <= lg[n + n]; i++) 
		for (int j = 0; j + pw(i) <= n + n; j++) f[i][j] = min(f[i - 1][j], f[i - 1][j + pw(i - 1)]);

	for (int i = 0; i < n; i++) {
		int l = 1;
		int r = n + 1;

		while (l < r) {
			int mid = (l + r) / 2;
			int w = lg[mid + 1];

			int val = min(f[w][i], f[w][i + mid - pw(w) + 1]);
			if (val + val < a[i]) r = mid; else l = mid + 1;
		}
		if (l > n) l = 3 * n;
		t[i] = l;
	}
	int id = -1;
	for (int i = 0; i < n; i++) if (id == -1 || a[i] > a[id]) id = i;

	ans[id] = t[id];
	for (int i = 1; i < n; i++) {
		int d = (id - i + n ) % n;
		int dd = (d + 1) % n;

		ans[d] = min(t[d], 1 + ans[dd]);
	}
	for (int i = 0; i < n; i++) {
		if (ans[i] > 2 * n + 1) ans[i] = -1;
		cout << ans[i] << " ";
	}

	return 0;
}