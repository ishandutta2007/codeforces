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
#include <queue>
#include <deque>
#include <stack>
#include <complex>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#ifdef LOCAL
#define LLD "%I64d"
#else
#define LLD "%I64d"
#endif
 
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;
 
const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int MOD = int(1e9) + 7;

int a[100100], b[100100];

inline void norm(int &a){
	while(a >= MOD){
		a -= MOD;
	}
}

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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int ans = 0;
	for(int i = 1; i <= a[n - 1]; i++){
		int k = 0;
		for(int j = 1; j * j <= i; j++){
			if(i % j == 0){
				b[k++] = j;
				if(i / j != j){
					b[k++] = i / j;
				}
			}
		}
		sort(b, b + k);
		int res = 1, g = 0;
		for(int j = 0; j < k - 1; j++){
			int sz = lower_bound(a, a + n, b[j + 1]) - lower_bound(a, a + n, b[j]);
			res = (ll(res) * calc(j + 1, sz)) % MOD;
		}
		int sz = a + n - lower_bound(a, a + n, b[k - 1]);
		ll mul = (calc(k, sz) - calc(k - 1, sz) + MOD) % MOD;
		res = (ll(res) * mul) % MOD;
		ans += res;
		norm(ans);
	}
	printf("%d\n", ans);
	return 0;
}