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
#define N 311111

#define TASK "1"

using namespace std;

int n;
int fu[N], inv[N];

int C(int n, int k) {
	return fu[n] * 1ll * inv[k] % M * inv[n - k] % M;
}

int pv(int a, int b) {
	if (b == 0) return 1;
	long long r = pv(a, b / 2);
	r = r * r % M;
	if (b % 2) r = r * a % M;
	return r;
}

int solve(vector<int> a, int t) {
	int n = a.size();
	if (n == 1) return a[0];

	if ((n % 4 == 1 || n % 4 == 2) && t == 0) {	
		int aa = (n - 1) / 2;

		int ret = 0;
		if (n % 4 == 1) {
			for (int i = 0; i < n; i++) if (i % 2 == 0) {
				ret = (ret + a[i] * 1ll * C(aa, i / 2)) % M;
			}
		} else {
			for (int i = 0; i < n; i++) {
				ret = (ret + a[i] * 1ll * C(aa, i / 2)) % M;
			}
		}
		return ret;

	}

		vector<int> b;
		for (int j = 0; j < n - 1; j++) {
			if (t == 0) b.pb((a[j]  + a[j + 1]) % M); else b.pb((a[j] - a[j + 1] + M) % M);
			t ^= 1;
		}
	return solve(b, t); 
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);

	fu[0] = 1;
	for (int i = 1; i <= 300000; i++) fu[i] = fu[i - 1] * 1ll * i % M;
	for (int i = 0; i <= 300000; i++) inv[i] = pv(fu[i], M - 2) % M;

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << solve(a, 0) << endl;
	return 0;
}