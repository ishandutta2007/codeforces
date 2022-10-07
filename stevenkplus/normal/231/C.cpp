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
//#johnnyho
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
#define rall(x) (x).rbegin(), (x).rend()
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
ll ar[MAXN]; // sorted 
ll sum[MAXN];
int N;
ll K;
ll cost(int x, int num) {
	ll s = sum[x] - sum[x - num];
	return num * ar[x] - s;
}
int most(int x) {
	int low = 0;
	int high = x;
	while (low < high) {
		int mid = (low + high + 1) / 2;
		if (cost(x, mid) <= K) {
			low = mid;
		} else {
			high = mid - 1;
		}
	}
	return low + 1;
}
int main() {
	N = nextInt();
	K = nextInt();
	rep(i,N) {
		ar[i] = nextInt();
	}
	sort(ar, ar + N);
	rep(i,N) {
		sum[i + 1] = sum[i] + ar[i];
	}
	int m = 0;
	int bestnum = 0;
	rep(i,N) {
		int k = most(i);
		if (k > m) {
			m = k;
			bestnum = ar[i];
		}
	}
	cout << m << " " << bestnum << endl;
}