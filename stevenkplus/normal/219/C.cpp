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
int conv(char c) {
	return c - 'A';
}
int main() {
	int n = nextInt(), k = nextInt();
	string s = next();
	string ret;
	int m = inf;
	if (k == 2) {
		rep(i,2) {
			int k = i;
			int cnt = 0;
			string tmp;
			repi(c,s) {
				char p = char(k + 'A');
				tmp += p;
				if (p != *c)
					cnt++;
				k = 1 - k;
			}
			if (cnt < m) {
				m = cnt;
				ret = tmp;
			}
		}
	} else {
		int x = 1;
		int cnt = 0;
		ret += s[0];
		while (x < n) {
			if (s[x] == s[x - 1]) {
				cnt++;
				int a = conv(s[x - 1]);
				int b = 0;
				if (x + 1 < n)
					b = conv(s[x + 1]);
				int c = 0;
				if (a == 0 || b == 0) {
					c = 1;
					if (a == 1 || b == 1)
						c = 2;
				}
				char cc = char(c + 'A');
				ret += cc;
				if (x + 1 < n)
					ret += s[x + 1];
				x += 2;
			} else {
				ret += s[x];
				x++;
			}
		}
		m = cnt;
	}
	cout << m << endl;
	cout << ret << endl;
}