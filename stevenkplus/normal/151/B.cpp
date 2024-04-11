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
string names[MAXN];
bool taxi(int *num) {
	int a = num[0];
	rep(i,6) {
		if (a != num[i]) {
			return false;
		}
	}
	return true;
}
bool pizza(int *num) {
	int a = num[0];
	for (int i = 1; i < 6; i++) {
		if (num[i] >= a)
			return false;
		a = num[i];
	}
	return true;
}
int buff[10];
int main() {
	int n = nextInt();
	int tax = 0, piz = 0, girl = 0;
	vi taxp, pizp, girlp;
	rep(i,n) {
		int t = 0, p = 0, g = 0;
		int k = nextInt();
		names[i] = next();
		rep(j,k) {
			string ne = next();
			buff[0] = ne[0] - '0';
			buff[1] = ne[1] - '0';
			buff[2] = ne[3] - '0';
			buff[3] = ne[4] - '0';
			buff[4] = ne[6] - '0';
			buff[5] = ne[7] - '0';
			if (taxi(buff)) {
				t++;
			} else if (pizza(buff)) {
				p++;
			} else
				g++;
		}
		if (t == tax) {
			taxp.pb(i);
		}
		if (t > tax) {
			tax = t;
			taxp.clear();
			taxp.pb(i);
		}
		if (p == piz) {
			pizp.pb(i);
		}
		if (p > piz) {
			piz = p;
			pizp.clear();
			pizp.pb(i);
		}

		if (g == girl) {
			girlp.pb(i);
		}
		if (g > girl) {
			girl = g;
			girlp.clear();
			girlp.pb(i);
		}
	}
	cout << "If you want to call a taxi, you should call: ";
	string sep = "";
	repi(i,taxp) {
		cout << sep;
		sep = ", ";
		cout << names[*i];
	}
	cout << "." << endl;
	cout << "If you want to order a pizza, you should call: ";
	 sep = "";
	repi(i,pizp) {
		cout << sep;
		sep = ", ";
		cout << names[*i];
	}
	cout << "." << endl;
	cout
			<< "If you want to go to a cafe with a wonderful girl, you should call: ";
	 sep = "";
	repi(i,girlp) {
		cout << sep;
		sep = ", ";
		cout << names[*i];
	}
	cout << "." << endl;

}