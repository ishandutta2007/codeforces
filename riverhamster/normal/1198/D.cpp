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
const int N = 55;
char s[N][N];
int f[N][N][N][N], sum[N][N];
 
int dfs(int lx, int ly, int rx, int ry){
	int &res = f[lx][ly][rx][ry];
	if(res != -1) return res;
	if(sum[rx][ry] - sum[lx-1][ry] - sum[rx][ly-1] + sum[lx-1][ly-1] == 0) return res = 0;
	res = max(rx-lx+1, ry-ly+1);
	for(int i=lx; i<rx; i++)
		res = min(res, dfs(lx, ly, i, ry) + dfs(i+1, ly, rx, ry));
	for(int i=ly; i<ry; i++)
		res = min(res, dfs(lx, ly, rx, i) + dfs(lx, i+1, rx, ry));
	return res;
}
 
int main(){
	// File("d");
	memset(f, -1, sizeof f);
	int n; in(n);
	for(int i=1; i<=n; i++)
		scanf("%s", s[i] + 1);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + (int)(s[i][j] == '#');
	printf("%d\n", dfs(1, 1, n, n));
	return 0;
}