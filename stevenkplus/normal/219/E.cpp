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
map<int, int> IDmap; // map <ID,loc>
map<int, pii> locmap; //map<loc,pair<left interval index, right interval index>>
vector<pii> vec;
int cnt;

int N;
int loc(int a, int b) {
	int k = (a + b) / 2;
	k = min(max(k, 1), N);
	return k;
}

int dist(int a, int b) {
	int l = loc(a, b);
	return min(l - a, b - l);
}
struct comp {
	bool operator()(const int &a, const int &b) const {
		int d1 = dist(vec[a].fi, vec[a].se), d2 = dist(vec[b].fi, vec[b].se);
		if (d1 == d2)
			return loc(vec[a].fi, vec[a].se) > loc(vec[b].fi, vec[b].se);
		return d1 < d2;
	}
};
set<int, comp> s;

void put(pii a) {
	vec.pb(a);
	locmap[a.fi].se = cnt;
	locmap[a.se].fi = cnt;
	s.insert(cnt++);
}
int split(int k) {
	pii &i = vec[k];
	int mid = loc(i.fi, i.se);
	pii a = pii(i.fi, mid);
	pii b = pii(mid, i.se);
	put(a);
	put(b);
	return mid;
}
void join(int loc) {
	pii &p = locmap[loc];
	pii &a = vec[p.fi];
	pii &b = vec[p.se];
	s.erase(p.fi);
	s.erase(p.se);
	pii c = pii(a.fi, b.se);
	put(c);
}
int main() {
	N = nextInt();
	int M = nextInt();
	pii start = pii(-inf, inf);
	put(start);

	rep(i,M) {
		int t = nextInt();
		int ID = nextInt();
		if (t == 1) {
			int front = *s.rbegin();
			s.erase(front);
			int l = split(front);
			IDmap[ID] = l;
			cout << l << "\n";
		} else {
			int loc = IDmap[ID];
			join(loc);
		}

//		dwni(k,s) {
//			pii interval = vec[*k];
//			p(interval.fi);
//			p(interval.se);
//		}
//		cout << endl;

	}
}