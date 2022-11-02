#include <algorithm>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <queue>
#include <stack>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <map>
#include <ctime>
#include <bitset>
#include <complex>
#include <cassert>

using namespace std;

#define N3 1100
#define N4 11000
#define N5 110000
#define N6 1100000
#define eps 1e-8
#define inf 0x3f3f3f3e
#define INF 0x3f3f3f3f3f3f3f3e
#define PI 3.1415926535897932384626433832795
#define IMAX 2147483647

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define times eprintf("%d\n", clock())
#define x first
#define y second
#define lfind(a, n, b) lower_bound((a), (a)+n, (b))-(a)
#define ufind(a, n, b) upper_bound((a), (a)+n, (b))-(a)
#define sqr(a) ((a)*(a))
#define cub(a) ((a)*sqr(a))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a/gcd(a, b)*b)
#define beyond(r, c) (r<0 || c<0 || r>=R || c>=C)
#define mp(a, b) make_pair(a, b)
#define clr(a, b) memset(a, b, sizeof(a))
#define uni(a, n) sort(a, a+n); n=unique(a, a+n)-a;

#define two(a) (1<<(a))
#define twoL(a) (1LL<<(a))
#define cont(a, n) ((a)&two(n))
#define contL(a, n) ((a)&twoL(n))
#define bcount(a) __builtin_popcount(a)

#define dec register int i, j, k, u, v
#define rep(i, n) for (i=0; i<(n); i++)
#define go(i, a, b) for (i=(a); i<(b); i++)
#define rrep(i, n) for (i=(n)-1; i>=0; i--)
#define rgo(i, a, b) for (i=(b)-1; i>=(a); i--)
#define tcase int _, runs=0; for (scanf("%d", &_); _--; runs++)
#define queue(n) int qf, qb, q[(n)]
#define stack(n) int sp, stk[(n)]

typedef long long INT;
typedef unsigned int uint;
typedef unsigned long long UINT;
typedef long double ldouble;
typedef pair<double, double> pdd;
typedef pdd point;
typedef pair<int, int> pii;
typedef pair<int, pii> pi3;
typedef pair<uint, uint> puu;
typedef pair<INT, INT> PII;

template <class T> inline void smax(T &a, T b) { if (a<b) a=b; }
template <class T> inline void smin(T &a, T b) { if (a>b) a=b; }
template <class T> inline T power(T a, T b, T m) { T t(a), r(1), k(0);
	while (b) { if (cont(b, k)) r=(INT)r*t%m, b-=two(k); t=(INT)t*t%m; k++; }
	return r;
}

typedef priority_queue<int, vector<int>, greater<int> > PQ;

#define NN 300

PQ q;
int a[NN], b[NN][NN], t[NN], p[NN], tt[NN];

bool cmp(int u, int v) {
	return u>v;
}

int main () {
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
	
	dec, N, K, sum, cnt, ans, tmp, n, m;
	scanf("%d%d", &N, &K);
	rep(i, N) scanf("%d", a+i);
	rep(i, N) {
		k=0;
		go(j, i, N) b[i][k++]=a[j];
		sort(b[i], b[i]+k, cmp);
	}
	ans=-inf; m=0;
	rep(i, N) {
		q=PQ(); sum=0;
		go(j, i, N) {
			sum+=a[j]; q.push(a[j]);
			tmp=sum; smax(ans, sum);
			cnt=n=0;
			
			rep(k, min(m, K)) tt[n++]=p[k];
			rep(k, min(N-j-1, K)) tt[n++]=b[j+1][k];
			sort(tt, tt+n, cmp);

			for (k=0; k<K; k++) {
				if (q.empty()) break;
				if (k>=n) break;
				u=q.top(); q.pop(); t[cnt++]=u;
				v=tt[k];
				if (u>=v) break;
				tmp+=v-u; smax(ans, tmp);
			}
			for (k=0; k<cnt; k++) q.push(t[k]);
		}
		p[m++]=a[i]; sort(p, p+m, cmp);
	}
	printf("%d\n", ans);
	
	return 0;
}