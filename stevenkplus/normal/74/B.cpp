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
int ans();
int main() {
	int an = ans();
	if (an == -1)
		cout << "Stowaway" << endl;
	else
		cout << "Controller " << an << endl;
}
int ans() {
	int n = nextInt(), stow = nextInt(), contr = nextInt();
	next();
	int mov = next() == "head" ? -1 : 1;
	string s = next();
	int t;
	for (t = 0; t < sz(s); t++) {
		if (s[t] == '0') {
			if (stow < contr)
				stow--;
			else if (stow > contr)
				stow++;
			if (stow < 1)
				stow ++;
			else if (stow > n)
				stow --;
			if (stow == contr) {
				return t + 1;
			}
			contr += mov;
			if (contr < 1 || contr > n) {
				mov *= -1;
				contr += 2 * mov;
			}
			if (stow == contr) {
				return t + 1;
			}
		} else {
			stow = contr;
			contr += mov;
			if (contr < 1 || contr > n) {
				mov *= -1;
				contr += 2 * mov;
			}
		}

	}
	return -1;

}