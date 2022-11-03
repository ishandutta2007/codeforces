#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2E6 + 10;
const int MOD = 51123987;

int n;
char s[MAXN];
int f[MAXN << 1];
int start[MAXN], end[MAXN];

void manacher(int n, char s[], int f[]){
	int m = (n << 1) - 1;
	f[0] = 1;
	for (int i = 1, r = 0; i < m; ++i){
		f[i] = r + f[r] >= i ? min(r + f[r] - i, f[(r << 1) - i]) : 1 - i % 2;
		int a = (i - f[i]) >> 1, b = (i + f[i] + 1) >> 1;
		for (; 0 <= a && b < n && s[a] == s[b]; --a, ++b, f[i] += 2);
		if (r + f[r] < i + f[i])
			r = i;
	}
}

int main(){
	scanf("%d", &n);
	scanf("%s", s);
	manacher(n, s, f);
	for (int i = 0; i < 2 * n - 1; ++i){
		++start[i - f[i] + 1 >> 1];//i - f[i] is always odd
		--start[i + 2 >> 1];

		++end[i + f[i] - 1 >> 1];
		--end[i - 1 >> 1];
	}
	for (int i = 1; i < n; ++i)
		start[i] = (start[i] + start[i - 1]) % MOD;
	for (int i = n - 2; i >= 0; --i)
		end[i] = (end[i] + end[i + 1]) % MOD;

	ll sum = 0, ans = 0;
	for (int i = 0; i < n; ++i){
		ans = (ans + sum * start[i]) % MOD;
		sum = (sum + end[i]) % MOD;
	}
	ans = (sum * (sum - 1) / 2 - ans + MOD) % MOD;
	printf("%d\n", (int)ans);
	return 0;
}