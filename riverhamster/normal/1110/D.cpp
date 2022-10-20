#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1000005, MN = -(1<<30);
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
int a[N], f[N][3][3][3];

int main(){
	// freopen("d.in", "r", stdin);
	// freopen("d.out", "w", stdout);
	int n, m, x, ans = 0;
	in(n); in(m);
	for(int i=1; i<=n; ++i)
		in(x), ++a[x];
	for(int i=1; i<=m; i++){
		if(a[i] > 6){
			ans += (a[i] - 6) / 3;
			a[i] -= (a[i] - 6) / 3 * 3;
		}
	}
	// puts("");
	for(int i=3; i<=m; i++)
		for(int j=0; j<3; j++) //get a[i]
			for(int k=0; k<3; k++) //get a[i-1]
				for(int l=0; l<3; l++){ //get a[i-2]
					if(j + k + l <= a[i-2] && j + k <= a[i-1] && j <= a[i])
						f[i][j][k][l] = max(f[i-1][k][l][0], max(f[i-1][k][l][1], f[i-1][k][l][2])) + (a[i-2] - j - k - l) / 3 + j;
					else f[i][j][k][l] = MN;
					// printf("f[%d](%d, %d, %d) = %d\n", i, j, k, l, f[i][j][k][l]);
				}
	int res = 0;
	for(int j=0; j<3; j++)
		for(int k=0; k<3; k++)
			for(int l=0; l<3; l++)
				res = max(res, f[m][j][k][l] + (a[m-1] - j - k) / 3 + (a[m] - j) / 3);
	printf("%d\n", ans + res);
	return 0;
}