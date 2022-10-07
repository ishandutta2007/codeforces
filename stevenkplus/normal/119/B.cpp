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
int worst = inf, best = 0;
bool seen[MAXN];
int prof[MAXN];
int main() {
	int n = nextInt(), k = nextInt();
	int percard = n / k;
	int cards = 0;
	rep(i,n) {
		prof[i] = nextInt();
	}
	int q = nextInt();
	rep(i,q) {
		int sum = 0;
		rep(j,percard) {
			int c = nextInt() - 1;
			if(j==0 && !seen[c]) cards++;
			seen[c] = true;
			sum += prof[c];
		}
		if (sum < worst)
			worst = sum;
		if (sum > best)
			best = sum;
	}

	vi left;
	rep(i,n) {
		if (!seen[i])
			left.pb(prof[i]);
	}
	int size = sz(left);
	if (size >= percard && cards<k) {
		sort(left.begin(), left.end());
		int sum = 0;
		rep(i,percard) {
			sum += left[i];
		}
		if (sum < worst)
			worst = sum;
		sum = 0;
		rep(i,percard) {
			sum += left[size - 1 - i];
		}
		if (sum > best)
			best = sum;
	}
	printf("%.10f %.10f\n", worst / double(percard), best / double(percard));
}