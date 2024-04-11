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
const int N = int(1e5);

int a[N + 10], b[N + 10], c[2 * N + 10], x[2 * N + 10], cnt[2 * N + 10], s[2 * N + 10], pref[2 * N + 10];

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int sz = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		c[sz++] = a[i];
	}
	for(int i = 0; i < m; i++){
		scanf("%d", &b[i]);
		c[sz++] = b[i];
	}
	sort(c, c + sz);
	sz = unique(c, c + sz) - c;
	for(int i = 0; i < n; i++){
		cnt[lower_bound(c, c + sz, a[i]) - c]++;
	}
	for(int i = 0; i < m; i++){
		cnt[lower_bound(c, c + sz, b[i]) - c]--;
	}
	for(int i = sz - 1; i >= 0; i--){
		s[i] = s[i + 1] + cnt[i];
	}
	for(int i = 0; i < sz; i++){
		pref[i] = i;
		if(i > 0 && s[pref[i - 1]] >= s[pref[i]]){
			pref[i] = pref[i - 1];
		}
	}
	int ptr = sz, val = inf;
	while(ptr > 0){
		if(s[pref[ptr - 1]] - s[ptr] > 0){
			for(int i = pref[ptr - 1]; i < ptr; i++){
				x[i] = val;
			}
			val--;
			ptr = pref[ptr - 1];
			continue;
		}
		for(int i = 0; i < ptr; i++){
			x[i] = 1;
		}
		break;
	}
	ll sum = 0;
	for(int i = 0; i < sz; i++){
		sum += ll(x[i]) * cnt[i];
	}
	if(sum > 0){
		puts("YES");
	}
	else{
		puts("NO");
	}
	return 0;
}