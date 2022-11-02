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
typedef long double ld;

const int inf = int(1e9);
const ld eps = 1e-12;
const double pi = 4 * atan(double(1));
const int N = int(1e5);

struct point{
	ll x, y;
	
	point(){}
	
	point(ll _x, ll _y){
		x = _x;
		y = _y;
	}
	
};

ll a[N + 10], b[N + 10], d[N + 10];
int st[N + 10];

inline bool lq(ld a, ld b){
	return b - a > -eps;
}

inline bool bad(int p1, int p2, int p3){
	point v1 = point(b[p2] - b[p3], d[p2] - d[p3]);
	point v2 = point(b[p1] - b[p2], d[p1] - d[p2]);
	return lq(ld(v2.x) / v1.x, ld(v2.y) / v1.y);
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf(LLD, &a[i]);
	}
	for(int i = 0; i < n; i++){
		scanf(LLD, &b[i]);
	}
	int k = 0, ptr;
	for(int i = 0; i < n; i++){
		d[i] = (i > 0 ? a[i] * b[0] : 0);
		if(i > 0){
			while(ptr + 1 < k && a[i] * b[st[ptr + 1]] + d[st[ptr + 1]] < a[i] * b[st[ptr]] + d[st[ptr]]){
				ptr++;
			}
			d[i] = min(d[i], a[i] * b[st[ptr]] + d[st[ptr]]);
		}
		while(k >= 2 && bad(st[k - 2], st[k - 1], i)){
			k--;
		}
		ptr = max(min(ptr, k - 1), 0);
		st[k++] = i;
	}
	printf(LLD"\n", d[n - 1]);
	return 0;
}