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

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	ll ans = 0, l = 1, r = inf;
	while(l <= r){
		ll mid = (l + r) / 2, can = 0;
		for(int i = 0; i < n; i++){
			if(a[i] > mid){
				can = -1;
				break;
			}
			can = min(can + mid - a[i], mid);
		}
		if(can == mid){
			ans = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	printf(LLD"\n", ans);
	return 0;
}