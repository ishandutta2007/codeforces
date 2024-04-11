#include <cstdio>
#include <algorithm>
using namespace std;

#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
const int mod = 998244353;
inline int add(int x, int y){return x+y>=mod ? x+y-mod : x+y;}
inline int sub(int x, int y){return x-y<0 ? x-y+mod : x-y;}
inline int mul(int x, int y){return 1LL * x * y % mod;}
inline int power(int x, int y){
	int res = 1;
	for(; y; y>>=1, x = mul(x, x)) if(y & 1) res = mul(res, x);
	return res;
}

int C(int n, int m){
	int res = 1, tp = 1;
	for(int i=n-m+1; i<=n; i++) res = mul(res, i);
	for(int i=1; i<=m; i++) tp = mul(tp, i);
	return mul(res, power(tp, mod - 2));
}
const int N = 55, P = 105;
int l[N], r[N], p[P], len[P];
int f[N][P];

int main(){
	// File("cf1295f");
	int n, pc = 0, all = 1;
	scanf("%d", &n);
	// printf("C(7, 3) = %d\n", C(7, 3));
	for(int i=1; i<=n; i++){
		scanf("%d%d", l + i, r + i), ++r[i];
		p[++pc] = l[i]; p[++pc] = r[i];
		all = mul(all, r[i] - l[i]);
	}
	// printf("all = %d\n", all);
	sort(p+1, p+1+pc);
	pc = unique(p+1, p+1+pc) - p - 1;
	for(int i=1; i<=n; i++){
		l[i] = lower_bound(p+1, p+1+pc, l[i]) - p;
		r[i] = lower_bound(p+1, p+1+pc, r[i]) - p;
		// printf("%d : [%d, %d]\n", i, l[i], r[i]);
	}
	for(int i=1; i<pc; i++) len[i] = p[i+1] - p[i];//, printf("Len[%d] = %d\n", i, len[i]);
	for(int i=1; i<=pc; i++) f[0][i] = 1;
	for(int i=1; i<=n; i++){
		for(int j=pc-1; j>=1; j--){
			if(j >= l[i] && j + 1 <= r[i])
				for(int k=i-1; k>=0; k--){
					// printf("Update with k %d\n", k);
					f[i][j] = add(f[i][j], mul(f[k][j+1], C(len[j] + i - k - 1, i - k)));
					if(!(j >= l[k] && j+1 <= r[k])) break;
				}
			// else puts("Skipped");
			// printf("f[%d][%d] = %d\n", i, j, f[i][j]);
			f[i][j] = add(f[i][j], f[i][j+1]);
			// printf("Sum : f[%d][%d] = %d\n", i, j, f[i][j]);
		}
	}
	printf("%d\n", mul(f[n][1], power(all, mod - 2)));
	return 0;
}