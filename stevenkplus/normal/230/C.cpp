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
ll nextLong() {
	ll tmp;
	cin >> tmp;
	return tmp;
}
const int MAXN = 110, MAXM = 11000;
int ar[MAXN][MAXM];
int tmp[MAXM];
int main() {
	int N = nextInt(), M = nextInt();
	rep(i,N) {
		string s = next();
		rep(j,M) {
			tmp[j] = s[j] - '0';
		}
		int pr = -inf;
		rep(j,M)
			ar[i][j] = inf;
		rep(j,2*M) {
			if (tmp[j % M]) {
				pr = j;
				ar[i][j % M] = 0;
			} else {
				ar[i][j % M] = min(ar[i][j % M], j - pr);
			}
		}
		pr = inf;
		dwn(j,2*M) {
			if (tmp[j % M])
				pr = j;
			else {
				ar[i][j % M] = min(ar[i][j % M], pr - j);
			}
		}
		if (pr == inf) {
			cout << -1 << endl;
			return 0;
		}
	}
//	rep(i,N) {
//		string s;
//		rep(j,M)
//			s += (ar[i][j]+'0');
//		p(s);
//	}
	int m = inf;
	rep(i,M) {
		int sum = 0;
		rep(j,N) {
			sum += ar[j][i];
		}
		m = min(m, sum);
	}
	cout << m << endl;
}