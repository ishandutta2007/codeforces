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

int n, k;
int a[1000111], b[1000111];
int q[1000111], qq[1000111];
int q1, q2;
int qq1, qq2;

int d[1000111];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	cin >> n >> k;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]), a[i] *= 100;
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	for (int i = 0; i < n; i++) a[i] = min(a[i], b[i]);

	int u = n - 1;

	int mb = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (b[i] <= mb) mb = b[i];

		while (q1 - q2 > 0 && a[i] >= a[q[q1 - 1]]) q1--;
		q[q1++] = i;


		while (qq1 - qq2 > 0 && b[i] <= b[qq[qq1 - 1]]) qq1--;
		qq[qq1++] = i;

		for(;;) {
			while (q1 > q2 && q[q2] > u) q2++;
			while (qq1 > qq2 && qq[qq2] > u) qq2++;

			int t = 1e9 + 1;
	
			if (q1 > q2) t = min(t, a[q[q2]]);
			if (qq1 > qq2) t = min(t, b[qq[qq2]]);

			mb = max(mb, t);


			if (q1 > q2 && qq1 > qq2 && a[q[q2]] > b[qq[qq2]]) u--; else break;
		}

			while (q1 > q2 && q[q2] > u) q2++;
			while (qq1 > qq2 && qq[qq2] > u) qq2++;

		int t = 1e9 + 1;

		if (q1 > q2) t = min(t, a[q[q2]]);
		if (qq1 > qq2) t = min(t, b[qq[qq2]]);

		d[i] = max(t, mb);
	}
	sort(d, d + n);
	reverse(d, d + n);
	long double ans = d[n - 1];

	long double p = 1;
	for (int i = n - 1; i >= 1; i--) {
		int va = d[i] - d[i - 1];
		p /= (i + 1);
		p *= (i + 1 - k);
		ans -= va * p;
	}

	printf("%.10lf\n", (double)ans);

	return 0;
}