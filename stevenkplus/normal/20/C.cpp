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
struct edge {
	int to;
	ll length;
	edge() {
	}
	edge(int a, ll b) {
		to = a;
		length = b;
	}
};

const int MAXN = 100100, MAXM = 200100;
edge edgelist[MAXM];
vi neighbors[MAXN]; // array of vectors: each vector is a list of indices.
// each index corresponds to an edge out of a node (index i -> edge edgelist[i])
int from[MAXN]; // for printing out the path at the end
bool vis[MAXN];
ll mindist[MAXN];
void dijkstra() {
	rep(i,MAXN)
		mindist[i] = infl;
	mindist[1] = 0;
	//start at 1.
	//find shortest path to all nodes
	PQ pq;
	pq.push(plli(0, 1));
	while (!pq.empty()) {
		plli p = pq.top();
		pq.pop();
		ll curdist = p.fi;
		int cur = p.se;
		if (vis[cur])
			continue;

		vis[cur] = true;
		repi(eP,neighbors[cur]) {
			edge &e = edgelist[*eP];
			int to = e.to;
			if (!vis[to]) {
				ll nextdist = curdist + e.length;
				if (nextdist < mindist[to]) {
					mindist[to] = nextdist;
					from[to] = cur;
					pq.push(plli(nextdist, to));
				}
			}
		}
	}
}
int main() {
	int N = nextInt(), M = nextInt();
	int edgecount = 0;
	rep(i,M) {
		int a = nextInt(), b = nextInt(), c = nextInt();
		edge toB = edge(b, c);
		neighbors[a].pb(edgecount);
		edgelist[edgecount++] = toB;
		edge toA = edge(a, c);
		neighbors[b].pb(edgecount);
		edgelist[edgecount++] = toA;
	}
	dijkstra();
	vi ans;
	int dest = N;
	if (mindist[N] != infl) {
		while (dest) { // using from[1] == 0
			ans.pb(dest);
			dest = from[dest];
		}
		string sep;
		while (sz(ans)) {
			cout << sep << ans.back();
			ans.pop_back();
			sep = " ";
		}
		cout << endl;
	} else
		cout << -1 << endl;
}