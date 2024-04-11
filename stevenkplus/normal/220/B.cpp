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
const int MAXN = 100100;
const int MAXC = 1000;
vi v[MAXC];
int ar[MAXN];
int cnt[MAXN];
int mapp[MAXN];
int cands[MAXN];
int main() {
	int N = nextInt();
	int q = nextInt();
	rep(i,N) {
		ar[i] = nextInt();
		if (ar[i] < MAXN)
			cnt[ar[i]]++;
	}
	int k = 1;
	rep(i,N) {
		if (ar[i] < MAXN)
			if (cnt[ar[i]] >= ar[i]) {
				if (!mapp[ar[i]]) {
					cands[k] = ar[i];
					mapp[ar[i]] = k++;
				}
				v[mapp[ar[i]]].pb(i);
			}
	}
	rep(i,q) {
		int left = nextInt() - 1, right = nextInt() - 1;
		int cnt = 0;
		repr(cand,1,k) {
			int num = int(lower_bound(all(v[cand]), left) - v[cand].begin());
			int top = num + cands[cand];
			int z = sz(v[cand]);
			if (top <= z) {
				if (v[cand][top - 1] <= right
						&& (top == z || v[cand][top] > right)) {
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
}