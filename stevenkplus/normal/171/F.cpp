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
const int MAX = 1000000;
bool pr[MAX];
vi primes;
void genpr() {
	rep(i,MAX)
		pr[i] = true;
	pr[0] = pr[1] = false;
	rep(i,MAX) {
		if (pr[i]) {
			primes.pb(i);
			for (ll j = ll(i) * i; j < MAX; j += i)
				pr[j] = false;
		}
	}
//	cout << "generated " << sz(primes)<<endl;
}
bool ispr(ll l) {
	repi(ii,primes) {
		int i = *ii;
		if (l % i == 0)
			return false;
		if (i * i > l)
			break;
	}
	return true;
}
ll rev(ll l) {
	ll r = 0;
	while (l) {
		r *= 10;
		r += l % 10;
		l /= 10;
	}
	return r;
}
int main() {
	genpr();
	int nfound = 0;
	int N = nextInt();
	for (ll i = 2; i < ll(MAX) * MAX; i++) {
		if (ispr(i)) {
			ll k = rev(i);
			if (k != i && ispr(k)) {
				nfound++;
				if (nfound == N) {
					cout << i << endl;
					return 0;
				}
			}
		}
	}
}