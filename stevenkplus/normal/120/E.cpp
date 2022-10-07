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
const int MAXN = 1100;
int scores[MAXN];
string names[MAXN];
map<string, int> m;
string rank(int a, int b) {
	if (2 * a > b) {
		return "noob";
	}
	if (5 * a > b)
		return "random";
	if (10 * a > b)
		return "average";
	if (100 * a > b)
		return "hardcore";
	return "pro";
}
int _main() {
	int n = nextInt();
	int j = 0;
	rep(i,n) {
		string name = next();
		int score = nextInt();
		if (!m[name]) {
			m[name] = j + 1;
			names[j++] = name;
		}
		int ind = m[name] - 1;
		scores[ind] = max(scores[ind], score);
	}
	rep(i,j) {
		int higher = 0;
		rep(k,j) {
			if (scores[k] > scores[i])
				higher++;
		}
		cout << names[i] << " " << rank(higher, j) << "\n";
	}
	return 0;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T = nextInt();
	rep(i,T) {
		cout << ((nextInt() & 1) ^ 1) << endl;
	}
	return 0;
}