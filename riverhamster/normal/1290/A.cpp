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
const int N = 3505;
int a[N];
int mn[N][N], val[N];

int main(){
	// File("a");
	int T;
	gi(T);
	while(T--){
		int n, m, K;
		gi(n); gi(m); gi(K);
		K = min(K, m - 1);
		for(int i=1; i<=n; i++) gi(a[i]);
		// int len = (n + 2 - m) / 2;
		for(int i=1; i<=m; i++) val[i] = max(a[i], a[n - (m - i)]);//, printf("val[%d] = %d right %d\n", i, val[i], n - (m - i));
		for(int i=1; i<=m; i++){
			mn[i][i] = val[i];
			for(int j=i+1; j<=m+1; j++)
				mn[i][j] = min(mn[i][j-1], val[j]);
		}
		int res = 0;
		for(int i=0; i<=K; i++)
			res = max(res, mn[1+i][m-(K-i)]);
		printf("%d\n", res);
	}
	return 0;
}