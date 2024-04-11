#include <bits/stdc++.h>

#define eps 1e-7
#define sq(x) ((x)*(x))
#define cub(x) ((x)*(x)*(x))
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3fLL
#define MOD 1000000007
#define rep(i, a, b) for (i=(a); i<(b); i++)
#define bpt(x) __builtin_popcount(x)
#define isset(x, y) ((x)&(1<<(y)))
#define pb push_back
#define beyond(u, v) (u<0 || v<0 || u>=N || v>=M)
#define x first
#define y second
#define eprint(...) fprintf(stderr, __VA_ARGS)

#define FILEIO(name) \
	freopen(name".in", "r", stdin); \
	freopen(name".out", "w", stdout);

using namespace std;
typedef long long INT;
typedef double DO;
typedef pair<int, int> pii;

template<typename T, typename U> inline void smin(T &a, U b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, U b) {if(a<b) a=b;}

int n, m;
int a[22][22];

int can() {
	int i, j, cnt=0, ok=0, k, ii;
	for (i=0; i<n; i++) {
		for (j=cnt=0; j<m; j++) if (a[i][j]!=j+1) cnt++;
		if (cnt>4) return 0;
		if (cnt>2) ok=1;
	}
	if (!ok) return 1;
	for (i=0; i<m; i++) for (j=i+1; j<m; j++) {
		for (k=0; k<n; k++) {
			for (cnt=ii=0; ii<m; ii++) {
				if (ii==i) {if (a[k][j]!=ii+1) cnt++;}
				else if (ii==j) {if (a[k][i]!=ii+1) cnt++;}
				else if (a[k][ii]!=ii+1) cnt++;
			}
			if (cnt>2) break;
		}
		if (k==n) return 1;
	}
	return 0;
}

int main() {
	int i, j;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++) for (j=0; j<m; j++) scanf("%d", a[i]+j);
	
	if (can()) puts("YES");
	else puts("NO");
	
	return 0;
}