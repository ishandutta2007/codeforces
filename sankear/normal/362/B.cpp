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
const int N = 3333;
const int LEN = 10;

int n;
int a[N];
bool can[LEN * N * 2];

inline bool is_can(int l, int r){
	int lg = max(a[l] - LEN, 1), rg = min(a[r] + LEN, n);
	for(int i = 0; i <= rg - lg; i++){
		can[i] = false;
	}
	for(int i = lg; i < a[l]; i++){
		can[i - lg] = true;
	}
	for(int i = lg; i < rg; i++){
		int pos = lower_bound(a + l, a + r + 1, i) - a;
		if(pos < r + 1 && a[pos] == i){
			continue;
		}
		if(!can[i - lg]){
			continue;
		}
		if(i + 1 <= rg){
			can[i + 1 - lg] = true;
		}
		if(i + 2 <= rg){
			can[i + 2 - lg] = true;
		}
		if(i + 3 <= rg){
			can[i + 3 - lg] = true;
		}
	}
	for(int i = a[r] + 1; i <= rg; i++){
		if(can[i - lg]){
			return true;
		}
	}
	return false;
}

int main(){
	int m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &a[i]);
	}
	if(m == 0){
		puts("YES");
		return 0;
	}
	sort(a, a + m);
	if(a[0] == 1 || a[m - 1] == n){
		puts("NO");
		return 0;
	}
	int i = 0;
	while(i < m){
		int j = i;
		while(j + 1 < m && a[j + 1] - a[j] <= LEN){
			j++;
		}
		if(!is_can(i, j)){
			puts("NO");
			return 0;
		}
		i = j + 1;
	}
	puts("YES");
	return 0;
}