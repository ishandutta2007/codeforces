#include <cstdio>

const int N = 255, mod = 1000000007;
int add(int x, int y){return x+y>=mod ? x+y-mod : x+y;}
int sub(int x, int y){return x-y<0 ? x-y+mod : x-y;}
int mul(int x, int y){return 1LL * x * y % mod;}

int f[N][N], C[N][N];
int pk[N], pk1[N];
int n, k;

void pre(){
	C[0][0] = 1;
	for(int i=1; i<=n; i++){
		C[i][0] = 1;
		for(int j=1; j<=i; j++) C[i][j] = add(C[i-1][j], C[i-1][j-1]);
	}
	pk[0] = pk1[0] = 1;
	for(int i=1; i<=n; i++){
		pk[i] = mul(pk[i-1], k);
		pk1[i] = mul(pk1[i-1], k-1);
	}
}

int main(){
	// freopen("cf1228e.in", "r", stdin);
	// freopen("cf1228e.out", "w", stdout);
	scanf("%d%d", &n, &k);
	pre();
	for(int i=1; i<=n; i++) f[1][i] = mul(C[n][i], pk1[n-i]);//, printf("f[1][%d] = %d\n", i, f[1][i]);
	for(int i=2; i<=n; i++)
		for(int j=1; j<=n; j++){
			for(int p=1; p<j; p++)
				f[i][j] = add(f[i][j], mul(f[i-1][p], mul(C[n-p][j-p], mul(pk[p], pk1[n-j]))));
			f[i][j] = add(f[i][j], mul(f[i-1][j], sub(mul(pk1[n-j], pk[j]),pk1[n])));
		}
	printf("%d\n", f[n][n]);
	return 0;
}