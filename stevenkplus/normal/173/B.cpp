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
const int MAXN = 1100;
int row[MAXN], col[MAXN];
char grid[MAXN][MAXN];
bool visr[MAXN], visc[MAXN];
int main() {
	int n = nextInt(), m = nextInt();
	rep(i,n) {
		string s = next();
		rep(j,m) {
			grid[i][j] = s[j];
		}
	}
	row[n - 1] = 1;
	rep(t,n+m) {
		rep(i,n) {
			if (row[i] && !visr[i]) {
				visr[i] = true;
				rep(j,m) {
					if (grid[i][j] == '#') {
						if (!col[j] || col[j] > row[i] + 1)
							col[j] = row[i] + 1;
					}
				}
			}
		}
		rep(i,m) {
			if (col[i] && !visc[i]) {
				visc[i] = true;
				rep(j,n) {
					if (grid[j][i] == '#') {
						if (!row[j] || row[j] > col[i] + 1)
							row[j] = col[i] + 1;
					}
				}
			}
		}
	}
	cout << row[0] - 1 << endl;

}