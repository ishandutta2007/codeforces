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
struct triangle {
	pii points[3];
	triangle(int ar[6]) {
		rep(i,3) {
			points[i] = pii(ar[i + i], ar[i + i + 1]);
		}
	}
};
ll distsq(pii a, pii b) {
	ll dx = a.fi - b.fi, dy = a.se - b.se;
	return dx * dx + dy * dy;
}
bool right(triangle t) {
	pii a = t.points[0], b = t.points[1], c = t.points[2];
	if (a == b || a == c || b == c)
		return false;
	ll m = distsq(a, b), n = distsq(a, c), o = distsq(b, c);
	return m + n == o || m + o == n || o + n == m;
}
int main() {
	int *ar = new int[6];
	rep(i,6)
		ar[i] = nextInt();
	triangle t = triangle(ar);
	if (right(t)) {
		cout << "RIGHT" << endl;
	} else {
		bool almost = false;
		rep(i,6) {
			rep(j,2) {
				ar[i] += 3 * j - 1;
				if (right(triangle(ar))) {
					almost = true;
				}
			}
			ar[i]--;
			if (almost)
				break;
		}
		if (almost)
			cout << "ALMOST" << endl;
		else
			cout << "NEITHER" << endl;
	}
}