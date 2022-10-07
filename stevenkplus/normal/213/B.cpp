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
const int MAXN = 110;
ll ar[MAXN];
ll temp[MAXN];
ll dp[MAXN][MAXN];
ll mod = 1E9 + 7;
ll choose(int a, int b) {
	if (a < b)
		return 0;
	if (a == b)
		return 1;
	if (b == 0)
		return 1;
	ll &ret = dp[a][b];
	if (ret)
		return ret - 1;
	ret = (choose(a - 1, b) + choose(a - 1, b - 1)) % mod;

	ret++;
	return ret - 1;
}
int array[10];
int main() {
	int n = nextInt();
//	cout << choose(5, 2) << endl;
	rep(i,10) {
		array[i] = nextInt();
	}
	rep(i,MAXN)
		ar[i] = 0;
	ar[0] = 1;
	rep(ii,10) {
		int i = 9 - ii;
		int k = array[i];
		rep(j,MAXN)
			temp[j] = 0;
		for (int j = k; j <= n; j++) {
			for (int x = j; x <= n; x++) {
				if (i == 0)
					temp[x] += choose(x - 1, j) * ar[x - j];
				else
					temp[x] += choose(x, j) * ar[x - j];
				temp[x] %= mod;
			}
		}
		rep(j,MAXN) {
			ar[j] = temp[j];
		}
	}
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		sum = (sum + ar[i]) % mod;
	}
	cout << sum << endl;
}