#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long ll;
typedef double R;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

const R PI = acos(-1);
const int MAXN = 1<<20;
const int P = 998244353;

int inv[MAXN];
int frac[MAXN], frac1[MAXN];

int C(int n, int m){
	if(m < 0 || m > n)
		return 0;
	return (ll)frac[n] * frac1[m] % P * frac1[n-m] % P;
}

int pow1(int a, ll k){
	int ret = 1;
	for(int i = 62; i >= 0; i--){
		ret = (ll)ret * ret % P;
		if(1LL<<i & k)
			ret = (ll)ret * a % P;
	}
	return ret;
}

namespace MyCode {
int main(){
#ifdef LOCAL
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int n;
	int i, j, k;
	scanf("%d", &n);
	inv[1] = 1;
	for(i = 2; i <= n; i++)
		inv[i] = P - (ll)inv[P%i] * (P/i) % P;
	frac[0] = frac1[0] = 1;
	for(i = 1; i <= n; i++){
		frac[i] = (ll)frac[i-1] * i % P;
		frac1[i] = (ll)frac1[i-1] * inv[i] % P;
	}
	ll ans = 0;
	for(i = 1; i <= n; i++){
		int x = i%2 == 0 ? -1 : 1;
		ans += x * (ll)pow1(3, (ll)n*n - i*(n-1)) * C(n, i) * 2 % P;
	}
	for(i = 1; i <= n; i++){
		int x = i%2 == 0 ? -1 : 1;
		int a = pow1(3, n-i);
		ans += x * 3 * (ll)C(n, i) * (pow1(a-1, n) - pow1(a, n)) % P;
	}
	ans = (ans % P + P) % P;
	printf("%I64d\n", ans);
	return 0;
}
}

int main(){
	return MyCode::main();
}