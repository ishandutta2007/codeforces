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
vi primes;
const int MAXN = 1001000;
bool tmp[MAXN];
void prec() {
	tmp[0] = tmp[1] = true;
	rep(i,MAXN) {
		if (!tmp[i]) {
			repr(j,i,(i+MAXN-1)/i) {
				tmp[i * j] = true;
			}
			primes.pb(i);
//			if (sz(primes) < 10)
//				p(i);
		}
	}
}

bool ispr(int n) {
	if (n == 1)
		return false;
	repi(i,primes) {
		if (n == *i)
			return true;
		if (n % *i == 0)
			return false;
		if (ll(*i) * (*i) > n)
			return true;
	}
	return true;
}
bool ist(ll k) {
	ll lol = ll(sqrt(k));
	if (lol * lol == k) {
		return ispr(lol);
	}
	return false;
}
int main() {
	prec();
	int N = nextInt();
	rep(i,N) {
		ll k = nextLong();
		bool b = ist(k);
		cout << (b ? "YES" : "NO") << "\n";
	}
}