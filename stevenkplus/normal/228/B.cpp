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
const int MAXN = 60;
int a[MAXN][MAXN], b[MAXN][MAXN];
int main() {
	int N = nextInt(), M = nextInt();
	rep(i,N) {
		string s = next();
		rep(j,M) {
			a[i][j] = s[j] - '0';
		}
	}
	int N2 = nextInt();
	int M2 = nextInt();
	rep(i,N2) {
		string s = next();
		rep(j,M2) {
			b[i][j] = s[j] - '0';
		}
	}
	int ansx = 0;
	int ansy = 0;
	ll bestsum = 0;
	repr(x,-MAXN,MAXN) {
		repr(y,-MAXN,MAXN) {
			ll sum = 0;
			rep(i,MAXN) {
				int ii = i + x;
				if (ii < 0 || ii >= N2)
					continue;
				if (i < 0 || i >= N)
					continue;
				rep(j,MAXN) {
					int jj = j + y;
					if (jj < 0 || jj >= M2)
						continue;
					if (j < 0 || j >= M)
						continue;
					sum += a[i][j] * b[ii][jj];
				}
			}
			if (sum > bestsum) {
				bestsum = sum;
				ansx = x;
				ansy = y;
			}
		}
	}
	cout << ansx << " " << ansy << endl;
}