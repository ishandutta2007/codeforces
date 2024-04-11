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
#define rall(x) (x).rbegin(), (x).rend()
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
int main() {
	int N = nextInt(), d = nextInt(), l = nextInt();
	int add = (N + 1) / 2;
	int subtr = N - add;
	int high = add * l - subtr;
	int low = add - subtr * l;
	if (d >= low && d <= high) {
		vi v;
		if (d > 0) {
			int p = d + subtr;
			int extr = p - add;
			rep(i,N) {
				if (i % 2 == 0) {
					int e = min(extr, l - 1);
					extr -= e;
					v.pb(e + 1);
				} else
					v.pb(1);
			}
		} else {
			int p = -d + add;
			int extr = p - subtr;
			rep(i,N) {
				if (i % 2 == 1) {
					int e = min(extr, l - 1);
					extr -= e;
					v.pb(e + 1);
				} else
					v.pb(1);
			}
		}
		string sep;
		repi(i,v) {
			cout << sep << *i;
			sep = " ";
		}
		cout << endl;
	} else {
		cout << -1 << endl;
	}
}