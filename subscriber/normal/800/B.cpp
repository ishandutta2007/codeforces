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

int n;
int x[N], y[N];


long double ss(int i, int j ,int k) {
		long long A = y[j] - y[i];
		long long B = x[i] - x[j];
		long long C = -x[i] * A - y[i] * B;

		long long h = A * x[k] + B * y[k] + C;
		h = abs(h);

		return h / sqrt(A * A + B * B);
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

	x[n] = x[0];
	y[n] = y[0];


	long double ans = 1e50;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) if (i != j && (i + 1) % n != j) {
			ans = min(ans, ss(i, (i + 1) % n, j));
			ans = min(ans, ss(i, j, (i + 1) % n));
			ans = min(ans, ss((i + 1) % n, j, i));
		}
	}
	ans /= 2;
	printf("%.20f\n", (double)ans);
	return 0;
}