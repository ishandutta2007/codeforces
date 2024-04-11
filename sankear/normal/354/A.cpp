#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#define len(s) int((s).size())
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define LLD "%lld"
#else
#define eprintf(...) 42
#define LLD "%I64d"
#endif
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned long long lint;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;

const ll inf = ll(1e12);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5);

int a[N + 10];
ll s[N + 10];

int main(){
	int n;
	scanf("%d", &n);
	int cl, cr;
	scanf("%d %d", &cl, &cr);
	int ql, qr;
	scanf("%d %d", &ql, &qr);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		s[i] = (i > 0 ? s[i - 1] : 0) + a[i];
	}
	ll ans = inf;
	for(int i = -1; i < n; i++){
		ll res = 0;
		if(i >= 0){
			res += cl * s[i];
		}
		if(i + 1 < n){
			res += cr * (s[n - 1] - (i >= 0 ? s[i] : 0));
		}
		if(i + 1 < n - i - 1){
			res += qr * ll(max(n - i - 1 - i - 1 - 1, 0));
		}
		else{
			res += ql * ll(max(i + 1 - n + i + 1 - 1, 0));
		}
		ans = min(ans, res);
	}
	printf(LLD"\n", ans);
	return 0;
}