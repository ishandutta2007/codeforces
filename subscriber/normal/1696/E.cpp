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
#define M 1000000007
 
#define TASK "1"
 
using namespace std;

int n;
int sz[N];
int a[N];
int fu[N], inv[N];


int pv(int a, int b) {
	if (b == 0) return 1;
	long long r = pv(a, b / 2);
	r = (r * r) % M;
	if (b % 2) r = (r * a) % M;
	return r;
}

int gc(int n, int k) {
	if (n < k) return 0;
	return fu[n] * 1ll * inv[k] % M * inv[n - k] % M;
}
 
int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i <= n; i++) cin >> sz[i];
	int m = sz[0];
	if (m == 0) {
		cout << 0 << endl;
		return 0;
	}

	fu[0] = 1;
	for (int i = 1; i <= n + m + 1; i++) fu[i] = fu[i - 1] * 1ll * i % M;
	for (int i = 0; i <= n + m + 1; i++) inv[i] = pv(fu[i], M - 2);


	int ans = 0;
	for (int i = 0; i <= n; i++) {
		int t = gc(sz[i] + i, i + 1);
//		cout << t << endl;
		ans = (ans + t) % M;
	}
	cout << ans << endl;
		
	return 0;
}