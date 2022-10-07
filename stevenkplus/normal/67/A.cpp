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
typedef pair<ll, int> plli;
typedef vector<int> vi;
typedef stringstream ss;
typedef priority_queue<plli, vector<plli>, greater<plli> > PQ;

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

const int MAXN = 1100;
pii ar[MAXN];
int ar2[MAXN];

int num[MAXN];
bool eq[MAXN];
int get(int i) {
	return i >= 0 ? ar2[i] : 0;
}
int main() {
	int cnt = 0;
	int N = nextInt();
	string s = next();
	int I = 1;
	int p = 1;
	repi(c,s) {
		char ch = *c;
		if (ch == '=') {
			eq[p] = true;
		} else {
			if (ch == 'L') {
				cnt--;
			} else {
				cnt++;
			}
			ar[I++] = pii(cnt, p);
		}
		p++;
	}
	sort(ar, ar + I);
	rep(i,I) {
		int x = ar[i].se;
		int p = x + 1;
		while (eq[p]) {
			p++;
		}
		ar2[x] = max(get(x - 1) + 1, get(p) + 1);
		p = x + 1;
		while (eq[p]) {
			ar2[p] = ar2[x];
			p++;
		}
	}
	string sep;
	rep(i,N) {
		cout << sep << ar2[i];
		sep = " ";
	}
	cout << endl;
}