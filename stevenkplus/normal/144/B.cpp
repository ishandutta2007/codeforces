#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>
#include <functional>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef stringstream ss;
typedef priority_queue<pii, vector<pii>, greater<pii> > PQ;
typedef pair<pii, int> circ;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define clr(t,v) memset((t),(v),sizeof(t))
#define p(a) cout << #a << ": " << a << endl;

#define rep(i,n) for(int i=0,_##i=(n);i<_##i;++i)
#define dwn(i,n) for(int i=(n);--i>=0;)
#define repr(i,l,r) for(int i=(l),_##i=(r);i<_##i;++i)
#define dwnr(i,l,r) for(int i=(r),_##i=(l);--i>=_##i;)
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(),_##i=(a).end();i!=_##i;++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(),_##i=(a).rend();i!=_##i;++i)
const int inf = 1 << 30;
char buf[1000];
string nextLine(int length = 100) {
	cin.getline(buf, length);
	string s(buf);
	return s;
}
string next(int length = 100) {
	string tmp;
	cin >> tmp;
	return tmp;
}

int nextInt() {
	int tmp;
	scanf("%d", &tmp);
	return tmp;
}
const int MAXC = 1010;
int countt = 0;
circ circs[MAXC];
int c;
bool close(circ a, pii p) {
	ll dx = a.fi.fi - p.fi, dy = a.fi.se - p.se;
	ll distsq = dx * dx + dy * dy;
	return distsq <= a.se * a.se;
}
void check(pii p) {
	bool clos = false;
	rep (i,c) {
		if (close(circs[i], p)) {
			clos = true;
			break;
		}
	}
	if (!clos)
		countt++;

}
int main() {
	int xa = nextInt(), ya = nextInt(), xb = nextInt(), yb = nextInt();
	c = nextInt();
	rep(i,c) {
		int a = nextInt(), b = nextInt(), c = nextInt();
		circs[i] = circ(pii(a, b), c);
	}
	if (xa > xb) {
		int t = xa;
		xa = xb;
		xb = t;
	}
	if (ya > yb) {
		int t = ya;
		ya = yb;
		yb = t;
	}
	for (int x = xa; x <= xb; x++) {
		check(pii(x, ya));
		check(pii(x, yb));
	}
	for (int y = ya + 1; y < yb; y++) {
		check(pii(xa, y));
		check(pii(xb, y));
	}
	cout << countt << endl;

}