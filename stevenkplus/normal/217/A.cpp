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
const int MAXN = 100100;
int x[MAXN], y[MAXN];
int par[MAXN];
bool adj(int a, int b) {
	return x[a] == x[b] || y[a] == y[b];
}
int find(int n) {
	if (par[n] == n)
		return n;
	return par[n] = find(par[n]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		par[a] = b;
	}
}
int main() {
	rep(i,MAXN)
		par[i] = i;
	int N = nextInt();
	rep(i,N) {
		x[i] = nextInt();
		y[i] = nextInt();
	}
	rep(i,N) {
		rep(j,N) {
			if (i != j && adj(i, j))
				merge(i, j);
		}
	}
	int cnt = 0;
	rep(i,N) {
		if (par[i] == i)
			cnt++;
	}
	cout << cnt - 1 << endl;
}