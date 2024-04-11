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
vi ar;
int main() {
	int N = nextInt(), R = nextInt();
	if (N == 1 && R == 1) {
		cout << "0\nT" << endl;
		return 0;
	}
	int m = inf, ans;
	for (int i = 1; i < R; i++) {
		if (__gcd(R, i) != 1)
			continue;
		int k = 0;
		int a = R;
		int b = i;
		int s = 0;
		int moves = 0;
		while (b != 1) {
			s += a / b - 1;
			moves += a / b;
			k = 1 - k;
			int c = a % b;
			a = b;
			b = c;
		}
		moves += max(0, a - 1);
		s += max(0, a - 2);
		k = 1 - k;
		moves++;
		k = 1 - k;
		if (moves == N) {
			if (s < m) {
				m = s;
				ans = i;
			}
		}

	}
	if (m == inf)
		cout << "IMPOSSIBLE\n";
	else {
		cout << m << endl;
		int k = 0;
		int a = R;
		int b = ans;
		while (b != 1) {
			rep(i,a / b) {
				ar.pb(k);
			}
			k = 1 - k;
			int c = a % b;
			a = b;
			b = c;
		}
		rep(i,a-1) {
			ar.pb(k);
		}
		k = 1 - k;
		ar.pb(k);

		dwni(i,ar) {
//			printf("%d", *i);
			printf("%c", (*i == k ? 'T' : 'B'));
		}
		printf("\n");
	}
}