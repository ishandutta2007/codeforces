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
const int MAXN = 100100;
vi factors[MAXN];
void prec() {
	int p = 0;
	for (int i = 2; i < MAXN; i++) {
		if (!sz(factors[i])) {
			for (int j = i; j < MAXN; j += i) {
				factors[j].pb(p);
			}
			p++;
		}
	}
}
const int MAXP = 10100;
int taken[MAXP];
bool on[MAXN];
int main() {
	prec();
	int n = nextInt(), m = nextInt();
	rep(i,m) {
		bool adding = next() == "+";
		int next = nextInt();
		if (adding) {
			if (on[next]) {
				cout << "Already on\n";
			} else {
				int confl = 0;
				repi(i,factors[next]) {
					if (taken[*i]) {
						confl = taken[*i];
						break;
					}
				}
				if (confl) {
					cout << "Conflict with " << confl << "\n";
				} else {
					repi(i,factors[next]) {
						taken[*i] = next;
					}
					on[next] = true;
					cout << "Success\n";
				}
			}
		} else {
			if (!on[next]) {
				cout << "Already off\n";
			} else {
				repi(i,factors[next]) {
					taken[*i] = 0;
				}
				on[next] = false;
				cout << "Success\n";
			}
		}
	}
}