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

ll a[100100], d[100100], add1[100100], add2[100100];
int l[100100], r[100100];

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < n; i++){
		scanf(LLD, &a[i]);
	}
	for(int i = 0; i < m; i++){
		scanf("%d %d "LLD, &l[i], &r[i], &d[i]);
		l[i]--;
		r[i]--;
	}
	for(int i = 0; i < k; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		add1[x]++;
		add1[y + 1]--;
	}
	ll cur = 0;
	for(int i = 0; i < m; i++){
		cur += add1[i];
		add2[l[i]] += d[i] * cur;
		add2[r[i] + 1] -= d[i] * cur;
	}
	cur = 0;
	for(int i = 0; i < n; i++){
		cur += add2[i];
		printf(LLD" ", a[i] + cur);
	}
	printf("\n");
	return 0;
}