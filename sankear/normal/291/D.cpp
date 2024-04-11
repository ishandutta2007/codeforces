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

int a[10100], na[10100], b[10100];

inline bool myassert(bool fl){
	if(!fl){
		while(true);
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n - 1; i++){
		a[i] = 1;
	}
	for(int i = 0; i < k; i++){
		int ptr = n - 1;
		for(int j = n - 1; j >= 0; j--){
			while(ptr > 0 && a[j] + a[ptr - 1] <= n - j - 1){
				ptr--;
			}
			b[j] = ptr;
		}
		for(int j = 0; j < n; j++){
			printf("%d ", b[j] + 1);
			na[j] = a[j] + a[b[j]];
		}
		printf("\n");
		for(int j = 0; j < n; j++){
			a[j] = na[j];
		}
	}
	for(int i = 0; i < n; i++){
		myassert(a[i] == n - i - 1);
	}
	return 0;
}