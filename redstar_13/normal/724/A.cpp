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

char u[][111]={"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
char a[111], b[111];
int main() {
	int i, j;
	scanf("%s%s", a, b);
	for (i=0; i<7; i++) if (!strcmp(a, u[i])) break;
	for (j=0; j<7; j++) if (!strcmp(b, u[j])) break;
	int ok=(j-i+7)%7;
	if (ok==0 || ok==2 || ok==3) puts("YES");
	else puts("NO");
	return 0;
}