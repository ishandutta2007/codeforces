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
const int MAXL = 3100;
const int MOD = 1E9 + 7;
const int MAXN = 110;
pii ar[MAXN];
int N;
int L;
int dp[MAXL][MAXN][2];
int add(ll a, ll b) {
	return int((a + b) % MOD);
}
int get(int l, int prev, int p) {
	if (l == 0)
		return 1;
	int prwidth = 0;
	if (prev != N) {
		prwidth = ar[prev].fi;
		if (!p)
			prwidth = ar[prev].se;
	}
	if (l < prwidth)
		return 0;
	int &ret = dp[l][prev][p];
	if (ret)
		return ret - 1;
	rep(i,N) {
		if (i != prev) {
			if (prev == N || ar[i].fi == prwidth) {
				ret = add(ret, get(l - ar[i].fi, i, 0));
			}
			if ((prev == N || ar[i].se == prwidth) && ar[i].fi != ar[i].se) {
				ret = add(ret, get(l - ar[i].se, i, 1));
			}
		}
	}
	return ret++;
}
int main() {
	N = nextInt();
	L = nextInt();
	rep(i,N) {
		int a = nextInt();
		int b = nextInt();
		ar[i] = pii(a, b);
	}
	cout << get(L, N, 0) << endl;
}