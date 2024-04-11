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

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int MAXA = int(1e6);

int s[MAXA + 10];

inline int get_sum(int l, int r){
	r = min(r, MAXA);
	if(l > r){
		return 0;
	}
	return s[r] - s[l - 1];
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		int cur;
		scanf("%d", &cur);
		s[cur]++;
	}
	for(int i = 1; i <= MAXA; i++){
		s[i] += s[i - 1];
	}
	for(int ans = MAXA; ans > 0; ans--){
		bool good = true;
		for(int i = ans; i <= MAXA; i += ans){
			if(i == ans){
				if(get_sum(1, i - 1) > 0){
					good = false;
					break;
				}
			}
			int l1 = i, r1 = i + k;
			int l2 = i + ans, r2 = i + ans + k;
			if(r1 < l2){
				if(get_sum(r1 + 1, l2 - 1) > 0){
					good = false;
					break;
				}
			}
		}
		if(good){
			printf("%d\n", ans);
			break;
		}
	}
	return 0;
}