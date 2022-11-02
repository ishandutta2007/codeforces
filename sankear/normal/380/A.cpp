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
const int N = int(1e5) + 100;

struct block {
	int t, l, c;
	
	block(){}
	
	block(int _t, int _l, int _c){
		t = _t;
		l = _l;
		c = _c;
	}
	
};

int a[N];
block b[N];
ll num[N];

int main(){
	int n;
	scanf("%d", &n);
	int sz = 0, k = 0;
	for(int i = 0; i < n; i++){
		int t;
		scanf("%d", &t);
		if(t == 1){
			int x;
			scanf("%d", &x);
			b[k++] = block(1, x, -1);
			if(sz < N){
				a[sz++] = x;
			}
			continue;
		}
		int l, c;
		scanf("%d %d", &l, &c);
		b[k++] = block(2, l, c);
		for(int j = 0; j < c && sz < N; j++){
			for(int z = 0; z < l && sz < N; z++){
				a[sz++] = a[z];
			}
		}
	}
	ll cur = 0;
	for(int i = 0; i < k; i++){
		num[i] = cur + 1;
		cur += (b[i].t == 1 ? 1 : b[i].l * b[i].c);
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		ll cur;
		scanf(LLD, &cur);
		int pos = -1, l = 0, r = k - 1;
		while(l <= r){
			int mid = (l + r) / 2;
			if(num[mid] <= cur){
				pos = mid;
				l = mid + 1;
			}
			else{
				r = mid - 1;
			}
		}
		if(b[pos].t == 1){
			printf("%d ", b[pos].l);
			continue;
		}
		cur = (cur - num[pos]) % b[pos].l;
		printf("%d ", a[cur]);
	}
	puts("");
	return 0;
}