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

int a[100100];
ll sum[100100];

inline ll get_sum(int l, int r){
	return sum[r] - (l > 0 ? sum[l - 1] : 0);
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
	for(int i = 0; i < n; i++){
		sum[i] = (i > 0 ? sum[i - 1] : 0) + a[i];
	}
	ll res = 0;
	for(int i = 0; i < n; i++){
		res += ll(n - i - 1) * a[i];
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int cur;
		scanf("%d", &cur);
		if(cur == 1){
			printf(LLD"\n", res);
			continue;
		}
		int num = 1;
		ll ans = 0, ptr = n - 2, sz = cur;
		while(ptr >= 0){
			ans += num * get_sum(max(ptr - sz + 1, 0LL), ptr);
			ptr -= sz;
			num++;
			sz *= cur;
		}
		printf(LLD" ", ans);
	}
	printf("\n");
	return 0;
}