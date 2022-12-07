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
#define N 411111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n;
int a[N];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	double l = -20000;
	double r = 20000;


	double ans = 1e20;
	for (int it = 0; it < 85; it++) {
		double mid = (l + r) / 2;

		double ma = 0, mi = 0;

		double s1 = 0, s2 = 0;

		for (int i = 0; i < n; i++) {
			if (s1 < 0) s1 = 0;
			if (s2 > 0) s2 = 0;

			double t = a[i] - mid;

			s1 += t;
			s2 += t;
			ma = max(ma, s1);
			mi = min(mi, s2);
		}
		ans = min(ans, max(fabs(ma), fabs(mi)));
		if (fabs(ma) > fabs(mi)) l = mid; else r = mid;
	}
	printf("%.15lf\n", ans);
	return 0;
}