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

uint mask[100100], new_mask[100100];

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		uint a, b, c, d;
		scanf("%u.%u.%u.%u", &a, &b, &c, &d);
		mask[i] = (a << 24) + (b << 16) + (c << 8) + d;
	}
	uint cur_mask = 0, ptr = (uint(1) << 31);
	for(int i = 1; i <= 31; i++){
		cur_mask |= ptr;
		ptr >>= 1;
		for(int j = 0; j < n; j++){
			new_mask[j] = (mask[j] & cur_mask);
		}
		sort(new_mask, new_mask + n);
		if(unique(new_mask, new_mask + n) - new_mask == k){
			uint a, b, c, d;
			d = (cur_mask & 255);
			cur_mask >>= 8;
			c = (cur_mask & 255);
			cur_mask >>= 8;
			b = (cur_mask & 255);
			cur_mask >>= 8;
			a = cur_mask;
			printf("%u.%u.%u.%u\n", a, b, c, d);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}