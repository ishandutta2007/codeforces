#include <cstdio>

typedef long long ll;

const int MAXN = 100;
const ll MOD = 1E9 + 7;

int n, B, K, X;

struct matrix{
	ll a[MAXN][MAXN];

	matrix& operator=(const matrix &r){
		for (int i = 0; i< X; ++i)
			for (int j = 0; j < X; ++j)
				a[i][j] = r.a[i][j];
		return *this;
	}
};

matrix operator*(const matrix &l, const matrix &r){
	matrix ret;
	for (int i = 0; i < X; ++i)
		for (int j = 0; j < X; ++j){
			ret.a[i][j] = 0;
			for (int k = 0; k < X; ++k)
				ret.a[i][j] = (ret.a[i][j] + l.a[i][k] * r.a[k][j]) % MOD;
		}
	return ret;
}

int cnt[10];

int main(){
	scanf("%d%d%d%d", &n, &B, &K, &X);
	for (int t, i = 0; i < n; ++i){
		scanf("%d", &t);
		++cnt[t];
	}
	matrix T1, T2, e;
	for (int i = 0; i < X; ++i){
		for (int j = 0; j < X; ++j)
			T1.a[i][j] = T2.a[i][j] = 0;
		T1.a[i][i * 10 % X] = 1;
		for (int j = 1; j < 10; ++j)
			T2.a[i][(i + j) % X] += cnt[j];
	}
	T1 = T1 * T2;
	e = T1;
	for (int t = B - 1; t; t >>= 1){
		if (t & 1)
			T1 = T1 * e;
		e = e * e;
	}
	printf("%d\n", (int)T1.a[0][K]);
	return 0;
}