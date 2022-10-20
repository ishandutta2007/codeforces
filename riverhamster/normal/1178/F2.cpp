#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
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
const int N = 505, M = 1000005;
const ll mod = 998244353;
int _c[M], c[M], l[N], r[N], mn[2*N][2*N];
ll f[2*N][2*N];
vector<int> p[N];

int main(){
	// File("f2");
	int n, _m, m = 0;
	in(n); in(_m);
	for(int i=1; i<=_m; i++){
		in(_c[i]);
		if(_c[i] != _c[i-1]) c[++m] = _c[i];
	}
	if(m > 2 * n + 1){
		puts("0");
		return 0;
	}
	for(int i=1; i<=m; i++){
		if(l[c[i]] == 0) l[c[i]] = i;
		r[c[i]] = i;
		p[c[i]].push_back(i);
		mn[i][i] = mn[i][i-1] = c[i];
	}
	for(int l=1; l<m; l++)
		for(int i=1; i+l<=m; i++)
			mn[i][i+l] = min(c[i+l], mn[i][i+l-1]);
	for(int i=1; i<=n; i++) f[l[i]][r[i]] = 1;
	for(int i=1; i<=m+1; i++)
		for(int j=0; j<i; j++) f[i][j] = 1;//, printf("f[%d][%d] = 1\n", i, j);
	for(int l=1; l<m; l++){
		for(int i=1; i+l<=m; i++){
			int j = i + l, MN = mn[i][j], S = p[MN].size();
			ll ls = 0, rs = 0, ms = 1;
			for(int i=1; i<S; i++)
				ms = (ms * f[p[MN][i-1]+1][p[MN][i]-1]) % mod;
			// printf("p[%d][0] = %d p[%d][%d] = %d\n", MN, p[MN][0], MN, S-1, p[MN][S-1]);
			for(int k=p[MN][0]; k>=i; k--) ls = (ls + f[i][k-1] * f[k][p[MN][0]-1]) % mod;
			for(int k=p[MN][S-1]; k<=j; k++) rs = (rs + f[p[MN][S-1]+1][k] * f[k+1][j]) % mod;
			f[i][j] = ms * ls % mod * rs % mod;
			// printf("f[%d][%d]: ms = %lld MN = %d ls = %lld rs = %lld f = %lld\n", i, j, ms, MN, ls, rs, f[i][j]);
		}
	}
	printf("%lld\n", f[1][m]);
	return 0;
}