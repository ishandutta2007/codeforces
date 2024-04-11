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
const ll infl = ll(1) << 60;
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
	int length;
	edge(int a, int b) {
		to = a;
		length = b;
	}
};
PQ pq;
vector<edge> edgelist;
const int MAXN = 100100;
vi conn[MAXN];
bool vis[MAXN];
int mindist[MAXN];
int main() {
	rep(i,MAXN) {
		mindist[i] = inf;
	}

	int n = nextInt();
	int m = nextInt();
	int s = nextInt() - 1;
	int j = 0;
	rep(i,m) {
		int a = nextInt() - 1, b = nextInt() - 1, c = nextInt();
		edge e1 = edge(a, c);
		edge e2 = edge(b, c);
		edgelist.pb(e1);
		edgelist.pb(e2);
		conn[b].pb(j);
		conn[a].pb(j + 1);
		j += 2;
	}

	pq.push(pii(0, s));
	while (!pq.empty()) {
		pii p = pq.top();
		pq.pop();
		int &dist = p.fi;
		int &cur = p.se;
		if (!vis[cur]) {
			vis[cur] = true;
			mindist[cur] = dist;
			repi(OUT,conn[cur]) {
				edge &out = edgelist[*OUT];
				if (!vis[out.to]) {
					int newdist = dist + out.length;
					pq.push(pii(newdist, out.to));
				}
			}
		}
	}


	int count = 0;
	int l = nextInt();
	rep(i,n) {
		int &d = mindist[i];
		if (d > l)
			continue;
		if (d == l) {
			count++;
		} else {
			repi(E,conn[i]) {
				edge &e = edgelist[*E];
				int &o = e.to;
				if (mindist[o] > l) {
					count++;
				} else if (mindist[o] == l) {
					if (d + e.length > l) {
						count++;
					}
				} else {
					if (o > i) {
						int roundtrip = mindist[o] + mindist[i] + e.length;
						if (roundtrip == 2 * l)
							count++;
						if (roundtrip > 2 * l)
							count += 2;
					}
				}
			}
		}
	}
	cout << count << endl;
}