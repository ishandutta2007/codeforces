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
const int N = 100;
const int MOD = int(1e9) + 7;

char s[N + 10];
int d[N + 10];

inline int calc(int a, int b){
	int res = 1;
	while(b > 0){
		if(b % 2 != 0){
			res = (ll(res) * a) % MOD;
		}
		a = (ll(a) * a) % MOD;
		b /= 2;
	}
	return res;
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	gets(s);
	int n = strlen(s);
	d[0] = 0;
	for(int i = 1; i <= n; i++){
		d[i] = (2 * d[i - 1]) % MOD;
		if(s[n - i] == '1'){
			int res = calc(2, i - 1);
			res = (ll(res) * res) % MOD;
			d[i] = (d[i] + res) % MOD;
		}
	}
	printf("%d\n", d[n]);
	return 0;
}