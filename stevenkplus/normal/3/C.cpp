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
const int n = 3;
char ar[n][n];
bool win(char c) {
	rep(i,n) {
		bool good = true;
		rep(j,n) {
			if (ar[i][j] != c)
				good = false;
		}
		if (good)
			return true;
	}
	rep(i,n) {
		bool good = true;
		rep(j,n) {
			if (ar[j][i] != c)
				good = false;
		}
		if (good)
			return true;
	}
	bool good = true;
	rep(i,n) {
		if (ar[i][i] != c)
			good = false;
	}
	if (good)
		return true;
	good = true;
	rep(i,n) {
		if (ar[i][n - 1 - i] != c)
			good = false;
	}
	return good;
}
int main() {
	int a = 0, b = 0;
	rep(i,n) {
		string l = next();
		rep(j,n) {
			ar[i][j] = l[j];
			if (ar[i][j] == 'X')
				a++;
			if (ar[i][j] == '0')
				b++;
		}
	}
	bool wina = win('X');
	bool winb = win('0');
	if (a == b + 1) {
		if (winb)
			cout << "illegal" << endl;
		else if (wina)
			cout << "the first player won" << endl;
		else if (a + b == 9)
			cout << "draw" << endl;
		else
			cout << "second" << endl;
	} else if (a == b) {
		if (wina)
			cout << "illegal" << endl;
		else if (winb)
			cout << "the second player won" << endl;
		else
			cout << "first" << endl;
	} else
		cout << "illegal" << endl;
}