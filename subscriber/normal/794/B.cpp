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

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	int n, h;
	cin >> n >> h;

	double A, B;
	A = 0;
	B = h;
	double ss = h / 2.;
	for (int i = 0; i < n - 1; i++) {
		double l = A;
		double r = B;
		for (int it = 0; it < 300; it++) {
			double mid = (l + r) / 2;
			double s = (A + mid) / 2 / h * (mid - A);
			if (s > ss / n) r = mid; else l = mid; 
		}
		l = (l + r) / 2;
		printf("%.10lf\n", l);
		A = l;
	}
	return 0;
}