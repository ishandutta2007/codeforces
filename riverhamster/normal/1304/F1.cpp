#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void gi(T &x){
	char ch; x = 0;
	int f = 1;
	while(isspace(ch = getchar()));
	if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	x *= f;
}
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}
const int N = 55, M = 20100;
int s[N][M];
int f[N][M], pmx[N][M], smx[N][M];
int n, m, k;

int Sum(int i, int l, int r){
	if(l > m || r < 1) return 0;
	if(r > m) r = m;
	if(l < 1) l = 1;
	return s[i][r] - s[i][l-1];
}

int main(){
	// File("f1");
	gi(n); gi(m); gi(k);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++){
			gi(s[i][j]);
			s[i][j] += s[i][j-1];
		}
	for(int i=1; i<=m; i++) f[1][i] = Sum(1, i, i+k-1) + Sum(2, i, i+k-1), pmx[1][i] = max(pmx[1][i-1], f[1][i]);
	for(int i=m; i>=1; i--) smx[1][i] = max(smx[1][i+1], f[1][i]);
	for(int i=2; i<=n; i++){
		for(int j=1; j<=m; j++){
			for(int p=max(1, j-k+1); p<=min(m, j + k - 1); p++){
				// printf("p = %d\n", p);
				if(p < j) upmax(f[i][j], f[i-1][p] + Sum(i, p+k, j+k-1));
				else upmax(f[i][j], f[i-1][p] + Sum(i, j, p-1));
			}
			// printf("f[%d][%d] = %d\n", i, j, f[i][j]);
			if(j - k >= 1) upmax(f[i][j], pmx[i-1][j - k] + Sum(i, j, j+k-1));
			if(j + k <= m) upmax(f[i][j], smx[i-1][j + k] + Sum(i, j, j+k-1));
			f[i][j] += Sum(i+1, j, j+k-1);
			// printf("f[%d][%d] = %d\n", i, j, f[i][j]);
		}
		for(int j=1; j<=m; j++) pmx[i][j] = max(pmx[i][j-1], f[i][j]);
		for(int j=m; j>=1; j--) smx[i][j] = max(smx[i][j+1], f[i][j]);
	}
	printf("%d\n", pmx[n][m]);
	return 0;
}