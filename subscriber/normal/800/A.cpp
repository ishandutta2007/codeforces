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

int n, p;
int a[N], b[N];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> p;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		sum += a[i];
	}
	if (p >= sum) {
		cout << -1 << endl;
		return 0;
	}
	long double l = 0;
	long double r = 1e18;

	for (int it = 0; it < 200; it++) {
		long double mid = (l + r) / 2;

		long double have = mid * p;
		long double need = 0;

		for (int i =0; i < n; i++) if (b[i] - a[i] * mid < 0) need += -(b[i] - a[i] * mid);

		if (have > need) l = mid; else r = mid;
	}
	l = (l + r) / 2;

	printf("%.20f\n", (double) l);

	return 0;
}