#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<cassert>
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
#define N 2211111
typedef double dbl;

#define TASK "1"

using namespace std;

const int R = 100000;
const dbl eps = 1e-7;

int n;
int st1[N], st2[N], stn1, stn2;
int st[N], stn;


long long x3(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	return (c.F - a.F) * 1ll * (b.S - a.S) - (c.S - a.S) * 1ll * (b.F - a.F);
}


struct pt
{
    dbl x, y;
    pt(){}
    pt(dbl xx, dbl yy): x(xx), y(yy) {}
};
 
struct line
{
    dbl a, b, c;
    line(){}
    line(dbl aa, dbl bb, dbl cc): a(aa), b(bb), c(cc) {}
};
 
inline line serper(pt p1, pt p2)
{
    return line(2 * (p2.x - p1.x), 2 * (p2.y - p1.y), p1.x * p1.x + p1.y * p1.y - p2.x * p2.x - p2.y * p2.y);
}
 
inline dbl dist(pt p1, pt p2)
{
    dbl dx = p1.x - p2.x;
    dbl dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}
 
inline pt intersect(line l1, line l2)
{
    return pt((l1.b * l2.c - l1.c * l2.b) / (l1.a * l2.b - l1.b * l2.a),
              (l1.a * l2.c - l1.c * l2.a) / (l1.b * l2.a - l1.a * l2.b));
}
 
inline dbl getR(dbl x1, dbl y1, dbl x2, dbl y2, dbl x3, dbl y3)
{
    pt A = pt(x1, y1);
    pt B = pt(x2, y2);
    pt C = pt(x3, y3);
    line AB = serper(A, B);
    line BC = serper(C, B);
    pt O = intersect(AB, BC);
    dbl R = dist(A, O);
    assert(abs(dist(B, O) - R) < eps);
    assert(abs(dist(C, O) - R) < eps);
    return R;
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	vector<pair<int, int> > e;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);

		int xx = x - z;
		if (xx >= 0) {
			e.pb(mp(xx, y));		
		} else {
			int l = y - (-xx);
			int r = y + (-xx);
			l = max(0, l);
			r = min(r, R);

			e.pb(mp(0, l));
			e.pb(mp(0, r));
		}

		xx = x + z;
		if (xx <= R) {
			e.pb(mp(xx, y));		
		} else {
			int l = y - (xx - R);
			int r = y + (xx - R);
			l = max(0, l);
			r = min(r, R);

			e.pb(mp(R, l));
			e.pb(mp(R, r));
		}

		int yy = y - z;
		if (yy >= 0) {
			e.pb(mp(x, yy));
		} else {
			int l = x - (-yy);
			int r = x + (-yy);

			l = max(0, l);
			r = min(r, R);

			e.pb(mp(l, 0));
			e.pb(mp(r, 0));
		}

		yy = y + z;
		if (yy <= R) {
			e.pb(mp(x, yy));
		} else {
			int l = x - (yy - R);
			int r = x + (yy - R);

			l = max(0, l);
			r = min(r, R);

			e.pb(mp(l, R));
			e.pb(mp(r, R));
		}
	}
	sort(e.begin(), e.end());

	for (int i = 0; i < e.size(); i++) {
		while (stn1 > 1 && x3(e[st1[stn1 - 2]], e[st1[stn1 - 1]], e[i]) <= 0) stn1--;
		while (stn2 > 1 && x3(e[st2[stn2 - 2]], e[st2[stn2 - 1]], e[i]) >= 0) stn2--;

		st1[stn1++] = i;
		st2[stn2++] = i;
	}
	stn = 0;
	for (int i = 0; i < stn1; i++) st[stn++] = st1[i];
	for (int i = stn2 - 2; i > 0; i--) st[stn++] = st2[i];

//	for (int i = 0; i < stn; i++) cout << e[st[i]].F << " " << e[st[i]].S << endl;
	st[stn] = st[0];
	st[stn + 1] = st[1];

	pair<int, int> A, B, C;
	double ans = -1;
	for (int i = 0; i < stn; i++) {
		double s = getR(e[st[i]].F, e[st[i]].S, e[st[i + 1]].F, e[st[i + 1]].S, e[st[i + 2]].F, e[st[i + 2]].S);
		if (s > ans) {
			ans = s;
			A = e[st[i]];
			B = e[st[i + 1]];
			C = e[st[i + 2]];
		}
	}

	cout << A.F << " " << A.S << endl;
	cout << B.F << " " << B.S << endl;
	cout << C.F << " " << C.S << endl;

	return 0;
}