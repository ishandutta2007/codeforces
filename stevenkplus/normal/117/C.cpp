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
const ll infl = ll(1) << 60;
char buf[1000000];
string nextLine() {
	scanf("%[^\n]",buf);
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
const int MAXN = 5100;
int adj[MAXN][MAXN];
pii ar[MAXN];
int main() {
	int n = nextInt();
	nextLine();
	rep(i,n)
		ar[i] = pii(0, i);
	rep(i,n) {
		string s = nextLine();
		rep(j,n) {
			if (s[j] == '1') {
				adj[i][j] = 1;
				ar[i].fi++;
			}
		}
	}
	sort(ar, ar + n);
	int guy = -1;
	int gg = -1;
	rep(i,n) {
		if (ar[i].fi != i) {
			guy = ar[i].se;
			gg = i;
			break;
		}
	}
	if (guy == -1)
		cout << guy << "\n";
	else {
		int g1;
		for (g1 = gg + 1; !adj[guy][ar[g1].se] && g1 < n; g1++)
			;
		g1 = ar[g1].se;
		int g2;
		for (g2 = 0; !(adj[g2][guy] && adj[g1][g2]) && g2 < n; g2++)
			;
		cout << guy + 1 << " " << g1 + 1 << " " << g2 + 1 << "\n";
	}
}