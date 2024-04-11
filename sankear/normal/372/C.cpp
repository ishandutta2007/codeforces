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

const ll inf = ll(1e18);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int M = 333;
const int N = int(1.5e5) + 100;

struct tp {
	int a, b, t;
};

struct ts {
	ll val, max;
};

int k1, k2;
tp p[M];
ll f[N], nf[N];
ts s1[N], s2[N];

inline void init(){
	k1 = k2 = 0;
	s1[0].max = s2[0].max = -inf;
}

inline void add(int num){
	s2[++k2].val = f[num];
	s2[k2].max = max(s2[k2 - 1].max, f[num]);
}

inline void del(){
	if(k1 == 0){
		while(k2 > 0){
			s1[++k1].val = s2[k2].val;
			s1[k1].max = max(s1[k1 - 1].max, s2[k2].val);
			k2--;
		}
	}
	k1--;
}

inline ll get_max(){
	return max(s1[k1].max, s2[k2].max);
}

int main(){
	int n, m, dist;
	scanf("%d %d %d", &n, &m, &dist);
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &p[i].a, &p[i].b, &p[i].t);
		p[i].a--;
	}
	for(int i = 0; i < n; i++){
		f[i] = 0;
	}
	for(int i = 0; i < m; i++){
		init();
		int l = 0, r = -1;
		ll can = ll(dist) * (p[i].t - (i > 0 ? p[i - 1].t : 1));
		for(int j = 0; j < n; j++){
			while(r + 1 < n && r + 1 - j <= can){
				add(++r);
			}
			while(j - l > can){
				del();
				l++;
			}
			nf[j] = get_max() + p[i].b - abs(j - p[i].a);
		}
		for(int j = 0; j < n; j++){
			f[j] = nf[j];
		}
	}
	ll ans = -inf;
	for(int i = 0; i < n; i++){
		ans = max(ans, f[i]);
	}
	printf(LLD"\n", ans);
	return 0;
}