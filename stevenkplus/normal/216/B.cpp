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
const int MAXN = 110;
int size[MAXN];
bool cyc[MAXN];
int par[MAXN];
int find(int k) {
	if (par[k] == k)
		return k;
	return par[k] = find(par[k]);
}
int main() {
	int N = nextInt(), M = nextInt();
	rep(i,N) {
		par[i] = i;
		size[i] = 1;
	}
	rep(i,M) {
		int a = nextInt() - 1, b = nextInt() - 1;
		a = find(a);
		b = find(b);
		if (a == b) {
			cyc[a] = true;
		} else {
			par[a] = b;
			size[b] += size[a];
		}
	}
	int cnt = 0;
	int odd = 0;
	rep(i,N) {
		if (par[i] == i) {
			if (size[i] % 2 == 1) {
				if (cyc[i])
					cnt++;
				else
					odd++;
			}
		}
	}
	cnt += odd % 2;
	cout << cnt << endl;

}