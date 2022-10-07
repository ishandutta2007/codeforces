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
string str;
const int MAXN = 1000100;
const ll prime = 10090101;

ll hash[MAXN];

void prec() {
	repr(i,1,sz(str)+1) {
		hash[i] = prime * hash[i - 1] + str[i - 1];
	}
}
ll powdp[MAXN];
ll pow(int n) {
	if (n == 0)
		return 1;
	ll &ret = powdp[n];
	if (ret)
		return ret;
	ret = pow(n / 2) * pow(n / 2) * ((n % 2) ? prime : 1);
	return ret;
}
ll hsh(int x, int len) {
	return hash[x + len] - hash[x] * pow(len);
}
bool works(int length) {
	ll h = hsh(0, length);
	for (int i = 1; i + length < sz(str); i++) {
		if (hsh(i, length) == h)
			return true;
	}
	return false;
}

int main() {
	str = next();
	prec();
	int low = 0;
	int high = sz(str) - 2;
	while (low < high) {
		int mid = (low + high + 1) / 2;
		if (works(mid)) {
			low = mid;
		} else {
			high = mid - 1;
		}
	}
	int best = 0;
	rep(i,low+1) {
		if (hsh(0, i) == hsh(sz(str) - i, i)) {
			best = i;
		}
	}
	if (best)
		cout << str.substr(0, best) << endl;
	else
		cout << "Just a legend" << endl;
}