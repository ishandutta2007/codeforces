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
const int MAXN = 100100;
bool r[MAXN];
vector<pii> v;
int conv(char c) {
	switch (c) {
	case '(':
		return 0;
	case '[':
		return 1;
	case ']':
		return 2;
	default:
		return 3;
	}
}
bool match(int a, int b) {
	return a < b && a + b == 3;
}
int main() {
	string s = next();
	int N = sz(s);
	rep(i,N) {
		int k = conv(s[i]);
		if (sz(v) > 0 && match(v.back().fi, k)) {
			r[v.back().se] = true;
			r[i] = true;
			v.pop_back();
		} else {
			v.pb(pii(k, i));
		}
	}
	int len = 0;
	int m = 0;
	int cnt = 0;
	int l = 0;
	int end = 0;
	rep(i,N) {
		if (r[i]) {
			l++;
			if (s[i] == '[')
				cnt++;
		} else {
			l = 0;
			cnt = 0;
		}
		if (cnt >= m) {
			end = i + 1;
			len = l;
			m = cnt;
		}
	}
	printf("%d\n%s\n", m, s.substr(end - len, len).c_str());
}