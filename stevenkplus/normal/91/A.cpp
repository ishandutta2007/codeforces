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
const ll infl = ll(1) << 60;
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
const int MAXC = 30;
vi occ[MAXC];
int conv(char c) {
	return c - 'a';
}
int next(char c, int k) {
	vi &v = occ[conv(c)];
	int z = sz(v);
	if (!z)
		return -1;
	int low = 0, high = z - 1;
	if (v[high] <= k)
		return v[low];
	while (low < high) {
		int mid = (low + high) / 2;
		if (v[mid] > k)
			high = mid;
		else
			low = mid + 1;
	}
	return v[high];
}
int main() {
	string s = next();
	rep(i,sz(s)) {
		occ[conv(s[i])].pb(i);
	}
	rep(i,MAXC) {
		sort(occ[i].begin(), occ[i].end());
	}
	string b = next();
	int pos = -1;
	int num = 1;
	repi(c,b) {
		int p = next(*c, pos);
		if (p == -1) {
			num = -1;
			break;
		}
		if (p <= pos)
			num++;
		pos = p;
	}
	cout << num << endl;
}