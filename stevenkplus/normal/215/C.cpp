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
int ar(int a, int b) {
	return (2 * a + 1) * (2 * b + 1);
}
int main() {
	int n = nextInt(), m = nextInt(), S = nextInt();
	ll count = 0;
	rep(a1,(n+1)/2)
		rep(b1,(m+1)/2) {
//			p(a1);
//			p(b1);
			int ar1 = ar(a1, b1);
			if (ar1 == S) {
				int numrects = (n - 2 * a1) * (m - 2 * b1);
				count += (2 * (a1 + 1) * (b1 + 1) - 1) * numrects;
			}
			rep(a2,a1) {
				int k = 2 * (2 * a2 + 1);
				int j = S - (ar1 + (2 * a2 + 1) - ar(a2, b1));
				if (j % k == 0) {
					int b2 = j / k;
//					p(b2);
					if (a1 > a2 && b1 < b2) {
						int numrects = (n - 2 * max(a1, a2))
								* (m - 2 * max(b1, b2));
						if(numrects>0)
							count += 2 * numrects;
//						p(a1);p(a2);p(b1);p(b2);
					}
				}
			}
		}
	cout << count << endl;
}