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

double Ax, Ay, Bx, By, Cx, Cy;
int n;

double a[N], b[N], o[N];

pair<double, int> qa[N], qb[N];

double dist(double x, double y, double xx, double yy) {
	return sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> n;
	double sum = 0;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		o[i] = dist(x, y, Cx, Cy) * 2;
		sum += o[i];

		a[i] = dist(x, y, Ax, Ay) + dist(x, y, Cx, Cy);
		b[i] = dist(x, y, Bx, By) + dist(x, y, Cx, Cy);
	}
	for (int i = 0; i < n; i++) {
		qa[i] = mp(a[i] - o[i], i);
		qb[i] = mp(b[i] - o[i], i);
	}
	sort(qa, qa + n);
	sort(qb, qb + n);


	double ans = 1e20;
	for (int i = 0; i < min(5, n); i++) for (int j = 0; j < min(5, n); j++) if (qa[i].S != qb[j].S) {
		double t = sum + qa[i].F + qb[j].F;
		ans = min(ans, t);
	}
	for (int i = 0; i < n; i++) {
		ans = min(ans, sum - o[i] + a[i]);
		ans = min(ans, sum - o[i] + b[i]);
	}

	printf("%.10lf\n", ans);


	return 0;
}