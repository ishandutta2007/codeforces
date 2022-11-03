#include <cstdio>
#include <cstring>

typedef long long ll;

const int MAXN = 5E3 + 10;
const ll MOD = 1E9 + 7;

char s[MAXN];
int lcp[MAXN][MAXN];
ll f[MAXN][MAXN];

inline bool less(int i, int j, int len){
	int t = lcp[i][j];
	return t > len ? 0 : s[i + t] < s[j + t];
}

int main(){
	int n;
	scanf("%d%s", &n, &s);
	for (int i = n - 1; i >= 0; --i)
		for (int j = n - 1; j >= i; --j)
			lcp[i][j] = s[i] == s[j] ? lcp[i + 1][j + 1] + 1 : 0;
	f[0][0] = 1;
	ll ans = 0;
	for (int len = 0; len < n; ++len){
		for (int i = len; i < n; ++i){
			f[len][i] = (f[len][i] + (len ? f[len - 1][i - 1] : 0)) % MOD;
			if (s[i + 1] < '1')
				continue;
			int k = i + len + 1;
			if (k < n && less(i - len, k - len, len))
				f[len][k] += f[len][i];
			else if (k + 1 < n)
				f[len + 1][k + 1] += f[len][i];
		}
		ans += f[len][n - 1];
	}
	printf("%I64d\n", ans %= MOD);
	return 0;
}