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
struct node {
	int s1, s2;
	int tmp;
	node() {
		s1 = 1;
		s2 = 0;
		tmp = 1;
	}
};
const int MAXN = 50100;
node ar[MAXN];
pii edge[MAXN];
int main() {
	int n = nextInt(), k = nextInt();
	rep(i,n-1) {
		int a = nextInt() - 1, b = nextInt() - 1;
		edge[i] = pii(a, b);
	}
	rep(i,k) {
		rep(i,n) {
			ar[i].tmp = 0;
		}
		rep(i,n-1) {
			int a = edge[i].fi, b = edge[i].se;
			ar[a].tmp += ar[b].s1 - ar[a].s2;
			ar[b].tmp += ar[a].s1 - ar[b].s2;
		}
		rep(i,n) {
			int s2n = ar[i].tmp + ar[i].s2;
			ar[i].s2 = ar[i].s1;
			ar[i].s1 = s2n;
		}
	}
	ll sum = 0;
	rep(i,n) {
		sum += ar[i].tmp;
	}
	cout << sum / 2 << endl;
}