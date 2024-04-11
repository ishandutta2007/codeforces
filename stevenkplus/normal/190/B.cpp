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
struct circle {
	int x, y, r;
	circle(int a, int b, int c) {
		x = a;
		y = b;
		r = c;
	}
};

double ans(circle &a, circle &b) {
	double centdist = hypot(a.x-b.x,a.y-b.y);
	if (centdist < abs(a.r - b.r)) {
//		cout << "Config 1" << endl;
		return (abs(a.r - b.r) - centdist) / 2.;
	} else if (centdist > (a.r + b.r) ) {
//		cout << "Config 2" << endl;
		return (centdist - (a.r + b.r))/2.;
	} else {
//		cout << "Config 3" << endl;
		return 0;
	}
}
int main() {
	int a = nextInt(), b = nextInt(), c = nextInt();
	circle c1(a, b, c);
	a = nextInt();
	b = nextInt();
	c = nextInt();
	circle c2(a, b, c);
	printf("%.16f\n",ans(c1,c2));
}