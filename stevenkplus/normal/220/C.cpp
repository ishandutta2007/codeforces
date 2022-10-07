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
typedef pair<ll, int> plli;
typedef vector<int> vi;
typedef stringstream ss;
typedef priority_queue<plli, vector<plli>, greater<plli> > PQ;

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
const ll infl = 1LL << 60;
char buf[1000000];
string nextLine() {
	scanf("%[^\n]", buf);
//	getc(stdin);
	scanf("%*c");
	return string(buf);
}
string next() {
	scanf("%s", buf);
	return string(buf);
}

int nextInt() {
	int tmp;
	scanf("%d", &tmp);
	return tmp;
}

const int MAXN = 100100;
int ar1[MAXN];
int ar[MAXN];
int X = 0;
int dist(int n) {
	return ar[n] + X;
}
struct comp {
	bool operator ()(const int &a, const int &b) const {
		int x = ar[a];
		int y = ar[b];
		if (x == y)
			return a < b;
		return x < y;
	}
};
set<int, comp> pos, neg;
int main() {
	int n = nextInt();
	rep(i,n) {
		ar1[nextInt() - 1] = i;
	}
	rep(i,n) {
		int x = nextInt() - 1;
		ar[i] = ar1[x] - i;
	}
	rep(i,n) {
		if (dist(i) >= 0)
			pos.insert(i);
		else
			neg.insert(i);
	}
	rep(x,n) {
		int posmin = sz(pos) ? abs(dist(*pos.begin())) : inf;
		int negmin = sz(neg) ? abs(dist(*neg.rbegin())) : inf;
		cout << min(posmin, negmin) << "\n";
		X++;
		pos.erase(x);
		ar[x] -= n;
		neg.insert(x);
		while (sz(neg) && dist(*neg.rbegin()) == 0) {
			pos.insert(*neg.rbegin());
			neg.erase(*neg.rbegin());
		}
	}
}