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
const int MAXN = 110;
const int MAXM = 100100;
pii edges[MAXM];

int dist[MAXN];
bool comefrom[MAXN][MAXN];
vi cancomefrom[MAXN];
int N;
ll dp[MAXN][MAXN];
ll numpathsTo(int n, int dest) {
	ll &ret = dp[dest][n];
	if (ret)
		return ret - 1;
	if (n == dest)
		ret = 1;
	else {
		repi(i,cancomefrom[n]) {
			ret += numpathsTo(*i, dest);
		}
	}
	return ret++;
}
int main() {
	N = nextInt();
	int M = nextInt();
	repr(i,1,N) {
		dist[i] = inf;
	}
	rep(i,M) {
		int a = nextInt() - 1, b = nextInt() - 1;
		edges[2 * i] = pii(a, b);
		edges[2 * i + 1] = pii(b, a);
	}
	rep(i,N) {
		rep(j,M*2) {
			int source = edges[j].fi;
			int dest = edges[j].se;
			if (dist[source] != inf) {
				if (dist[source] + 1 < dist[dest]) {
					dist[dest] = dist[source] + 1;
					rep(k,N) {
						comefrom[dest][k] = false;
					}
				}
				if (dist[source] + 1 == dist[dest]) {
					comefrom[dest][source] = true;
				}
			}
		}
	}
	rep(i,N) {
		rep(j,N) {
			if (comefrom[i][j])
				cancomefrom[i].pb(j);
		}
	}
	ll np = numpathsTo(N - 1, 0);
	ll m = 0;
	repr(i,1,N-1) {
		if (dp[0][i]) {
			ll k = numpathsTo(i, 0) * numpathsTo(N - 1, i);
			m = max(m, k * 2);
		}
	}
//	p(np);
//	p(m);
	double av = double(m) / np;
	if (av < 1)
		av = 1.0;
	printf("%.16f\n", av);
}