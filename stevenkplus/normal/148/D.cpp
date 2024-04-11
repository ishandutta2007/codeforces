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
typedef pair<pii, int> circ;

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
char buf[1000];
string nextLine(int length = 100) {
	cin.getline(buf, length);
	string s(buf);
	return s;
}
string next(int length = 100) {
	string tmp;
	cin >> tmp;
	return tmp;
}

int nextInt() {
	int tmp;
	scanf("%d", &tmp);
	return tmp;
}
const int MAXN = 2100;
double dp[MAXN][MAXN];
double eps = 1E-15;
double get(int tot, int white) {
	if (!white)
		return 0;
	if (white == tot)
		return 1;
	double &ret = dp[tot][white];
	if (abs(ret-(-1))>eps)
		return ret;
	ret = double(white) / tot;
	if (tot > 3) {
		double other = double(tot - white) / tot * double(tot - 1 - white)
				/ (tot - 1);
		double otherp = double(white) / (tot - 2) * get(tot - 3, white - 1);
		if (tot - 2 > white)
			otherp += double(tot - 2 - white) / (tot - 2) * get(tot - 3, white);
		ret += otherp * other;
	}
	return ret;
}
int main() {
	int w = nextInt(), t = w + nextInt();
	rep(i,MAXN)
		rep(j,MAXN)
			dp[i][j] = -1;

	double ans = get(t, w);
	printf("%.15f\n", ans);
}