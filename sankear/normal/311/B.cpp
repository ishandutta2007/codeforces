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

struct point{
	ll x, y;
	
	point(){}
	
	point(ll _x, ll _y){
		x = _x;
		y = _y;
	}
	
};

point operator - (const point &a, const point &b){
	return point(a.x - b.x, a.y - b.y);
}

int st[N + 100];
ll s[N + 100], t[N + 100], d[N + 100], nd[N + 100];
point p[N + 100];

inline ll get_sum(int l, int r){
	if(l > r){
		return 0;
	}
	return s[r] - (l > 0 ? s[l - 1] : 0);
}

inline ll vec(point &a, point &b){
	return a.x * b.y - b.x * a.y;
}

inline ll sqr(ll a){
	return a * a;
}

inline ll len(point &a){
	return sqr(a.x) + sqr(a.y);
}

inline bool bad(point &a, point &b, point &c){
	point v1 = b - a, v2 = c - b;
	return vec(v1, v2) < 0;
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, P;
	scanf("%d %d %d", &n, &m, &P);
	for(int i = 1; i < n; i++){
		int cur;
		scanf("%d", &cur);
		s[i] = s[i - 1] + cur;
	}
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		t[i] = b - s[a];
	}
	sort(t, t + m);
	for(int i = 0; i < m; i++){
		s[i] = (i > 0 ? s[i - 1] : 0) + t[i];
	}
	for(int i = 0; i < m; i++){
		d[i] = t[i] * (i + 1) - get_sum(0, i);
	}
	for(int i = 1; i < P; i++){
		int k = 0, ptr = 0;
		for(int j = 0; j < m; j++){
			while(ptr + 1 < k && d[st[ptr + 1]] + t[j] * (j - st[ptr + 1]) - get_sum(st[ptr + 1] + 1, j) < d[st[ptr]] + t[j] * (j - st[ptr]) - get_sum(st[ptr] + 1, j)){
				ptr++;
			}
			nd[j] = d[st[ptr]] + t[j] * (j - st[ptr]) - get_sum(st[ptr] + 1, j);
			p[j] = point(j, d[j] + s[j]);
			while(k >= 2 && bad(p[st[k - 2]], p[st[k - 1]], p[j])){
				k--;
			}
			ptr = min(ptr, max(k - 1, 0));
			st[k++] = j;
		}
		for(int j = 0; j < m; j++){
			d[j] = nd[j];
		}
	}
	printf(LLD"\n", d[m - 1]);
	return 0;
}