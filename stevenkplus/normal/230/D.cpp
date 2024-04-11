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
//#johnnyho
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
const int MAXM = 100100, MAXN = 100100;

pii edges[MAXM];
vi con[MAXN];
int mindist[MAXN];
bool vis[MAXN];
set<pii> s;

PQ pq;
int main() {
	int N = nextInt(), M = nextInt();
	int x = 0;
	rep(i,M) {
		int a = nextInt() - 1;
		int b = nextInt() - 1;
		int c = nextInt();
		pii e1 = pii(a, c);
		pii e2 = pii(b, c);
		edges[x] = e1;
		edges[x + 1] = e2;
		con[a].pb(x + 1);
		con[b].pb(x);
		x += 2;
	}
	rep(i,N) {
		int k = nextInt();
		rep(j,k) {
			int a = nextInt();
			pii p = pii(a, i);
			s.insert(p);
		}
	}
	rep(i,N) {
		mindist[i] = inf;
	}
	pq.push(pii(0, 0));
	while (sz(pq)) {
		pii p = pq.top();
		pq.pop();
		int &loc = p.se;
		int &dist = p.fi;
		if (vis[loc])
			continue;
		vis[loc] = true;
		if (loc == N - 1)
			break;
		while (s.find(p) != s.end()) {
			dist++;
		}
		repi(eP,con[loc]) {
			pii &p = edges[*eP];
			int to = p.fi;
			int d = dist + p.se;
			if (d < mindist[to]) {
				mindist[to] = d;
				pii p = pii(d, to);
				pq.push(p);
			}
		}
	}
	int ans = mindist[N - 1];
	if (ans == inf)
		ans = -1;
	cout << ans << endl;
}