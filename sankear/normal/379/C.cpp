#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <complex>
#include <queue>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define LLD "%lld"
#else
#define eprintf(...) 42
#define LLD "%I64d"
#endif
#define fs first
#define sc second
#define next _next
#define prev _prev
#define hash _hash
#define link _link
#define y0 yy0
#define y1 yy1

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;
typedef long double ld;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(3e5) + 100;

pii a[N];
ll b[N];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i].fs);
		a[i].sc = i;
	}
	sort(a, a + n);
	ll cur = 0;
	for(int i = 0; i < n; i++){
		cur = max(cur + 1, 1LL * a[i].fs);
		b[a[i].sc] = cur;
	}
	for(int i = 0; i < n; i++){
		printf(LLD" ", b[i]);
	}
	puts("");
	return 0;
}