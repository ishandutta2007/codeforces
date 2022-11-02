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
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const ll MOD = ll(1e9) + 9;

inline ll calc(ll a, ll b){
	ll res = 1;
	while(b > 0){
		if(b % 2 != 0){
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		b /= 2;
	}
	return res;
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	ll need = m - ll(k - 1) * (n / k) - n % k + 1;
	need = max(need, 1LL);
	ll ans = (calc(2, need) - 2 + MOD) % MOD;
	ans = (ans * k) % MOD;
	ans = (ans - (need - 1) * k + m) % MOD;
	ans = (ans + MOD) % MOD;
	printf(LLD"\n", ans);
	return 0;
}