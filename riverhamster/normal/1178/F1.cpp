#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(IO_Filename) freopen(IO_Filename".in", "r", stdin), freopen(IO_Filename".out", "w", stdout)
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	char ch; x = 0;
	// int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
const int N = 505;
const ll mod = 998244353;
int c[N], mn[N][N], pos[N];
ll f[N][N];
#define minpos(x, y) (c[x] < c[y] ? x : y)

int main(){
	// File("f");
	int n, m;
	in(n); in(m);
	for(int i=1; i<=m; i++) in(c[i]), mn[i][i] = i;
	for(int l=1; l<m; l++)
		for(int i=1; i+l<=m; i++)
			mn[i][i+l] = minpos(mn[i][i+l-1], i+l);
	for(int i=1; i<=m; i++) f[i][i] = 1, f[i][i-1] = 1;
	f[m+1][m] = 1;
	for(int l=1; l<m; l++)
		for(int i=1; i+l<=m; i++){
			int j = i + l, MN = mn[i][j];
			ll ls = 0, rs = 0;
			for(int k=MN; k>=i; k--) ls = (ls + f[i][k-1] * f[k][MN-1]) % mod;
			for(int k=MN; k<=j; k++) rs = (rs + f[MN+1][k] * f[k+1][j]) % mod;
			f[i][j] = ls * rs % mod;
		}
	printf("%lld\n", f[1][m]);
	return 0;
}