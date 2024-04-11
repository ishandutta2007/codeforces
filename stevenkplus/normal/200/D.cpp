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
struct func {
	string name;
	vi params;
	func(string n, vi p) {
		name = n;
		params = p;
	}
};
bool match2(int a, int b) {
	if (b == 1)
		return true;
	if (a == b)
		return true;
	return false;
}
bool match(vi a, vi b) {
	if (a.size() == b.size()) {
		rep(i,a.size()) {
			if (!match2(a[i], b[i]))
				return false;
		}
		return true;
	}
	return false;
}
vector<func> vec;
int main() {
	map<string, int> types;
	map<string, int> vars;
	types["T"] = 1;
	types["int"] = 2;
	types["double"] = 3;
	types["string"] = 4;
	int N = nextInt();
	nextLine();
	rep(i,N) {
		string line = nextLine();
		int x = 0;
		while (line[x] == ' ')
			x++;
		while (line[x] != ' ')
			x++;
		while (line[x] == ' ')
			x++;
		string name;
		while (line[x] != '(') {
			if (line[x] != ' ')
				name += line[x];
			x++;
		}
		x++;
		while (line[x] == ' ')
			x++;
		string cur;
		vi para;
		while (line[x] != ')') {
			if (line[x] == ',') {
				para.pb(types[cur]);
				cur = "";
			} else if (line[x] != ' ') {
				cur += line[x];
			}
			x++;
		}
		para.pb(types[cur]);
		vec.pb(func(name, para));
	}
	int M = nextInt();
	nextLine();
	rep(i,M) {
		string line = nextLine();
		int x = 0;
		while (line[x] == ' ')
			x++;
		string ty;
		while (line[x] != ' ') {
			ty += line[x];
			x++;
		}
		while (line[x] == ' ')
			x++;
		string name;
		while (x < int(line.length()) && line[x] != ' ')
			name += line[x++];
		vars[name] = types[ty];
	}
	int K = nextInt();
	nextLine();
	rep(i,K) {
		string line = nextLine();
		int x = 0;
		while (line[x] == ' ')
			x++;
		string name;
		while (line[x] != '(') {
			if (line[x] != ' ')
				name += line[x];
			x++;
		}
		x++;
		while (line[x] == ' ')
			x++;
		string cur;
		vi para;
		while (line[x] != ')') {
			if (line[x] == ',') {
				para.pb(vars[cur]);
				cur = "";
			} else if (line[x] != ' ') {
				cur += line[x];
			}
			x++;
		}
		int co = 0;
		para.pb(vars[cur]);
		repi(i,vec) {
			func f = *i;
			if (f.name == name) {
				if (match(para, f.params)) {
					co++;
				}
			}
		}
		printf("%d\n", co);
	}
}