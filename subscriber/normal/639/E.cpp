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
pair<int, int> q[N];

bool my (pair<int, int> a, pair<int, int> b) {
	return a.F * 1ll * b.S > a.S * 1ll * b.F;
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);

	cin >> n;


	for (int i = 0; i < n; i++) cin >> q[i].F;
	for (int i = 0; i < n; i++) cin >> q[i].S;

	long long T = 0;
	for (int i = 0; i < n; i++) T += q[i].S;

	sort(q, q + n, &my);

	double l = 0;
	double r = 1;
	vector<pair<int, pair<double, double> > > e;

	for (int it = 0; it < 50; it++) {
		double mid = (l + r) / 2;

		long long alt = 0;

		e.clear();

		for (int i = 0; i < n; ) {
			int j = i;
			while (j < n && q[i].F * 1ll * q[j].S == q[i].S * 1ll * q[j].F) j++;

			long long tt = 0;
			for (int k = i; k < j; k++) tt += q[k].S;


			for (int k = i; k < j; k++) {
				double t1 = q[k].F * (1 - mid * (alt + q[k].S) / T);
				double t2 = q[k].F * (1 - mid * (alt + tt) / T);

				e.pb(mp(q[k].F, mp(t2, t1)));
			}
			alt += tt;

			i = j;
		}
		sort(e.begin(), e.end());
/*		cout << mid << endl;
		for (int i = 0; i < e.size(); i++) cout << e[i].F << " " << e[i].S.F << " " << e[i].S.S << endl;
		cout << endl;*/
//		return 0;

		int bad = 0;

		double ma = -1;
		for (int i = 0; i < n; i) {
			int j = i;
			while (j < n && e[i].F == e[j].F) j++;
			for (int k = i; k < j; k++) if (e[k].S.F < ma) bad = 1;

			for (int k = i; k < j; k++) ma = max(ma, e[k].S.S);
			
			i = j;
		}
		if (bad) r = mid; else l = mid;
	}
	l = (l + r) / 2;
	printf("%.10lf\n", l);

	return 0;
}