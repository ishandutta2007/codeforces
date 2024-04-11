#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2E3 + 10, MAXM = 2E3 + 10;
const ll MOD = 1E9 + 7;

int n, m, d;
char a[MAXN], b[MAXN];

ll f[MAXN][MAXM];
int g[MAXN];

int count(char s[]){
	int cntd = 0;
	for (int i = n - 2; i >= 0; i -= 2)
		cntd = (cntd * 100 + d) % m;
	if (n & 1)
		cntd = cntd * 10 % m;
//	printf("%d %d\n", cntd, d);
	int e = n & 1 ? 1 : 10;
	memset(f, 0, sizeof(f));
	f[0][0] = 1;
	int j = 0;
	for (int i = !(n & 1); i < n; i += 2, ++j){
		g[j + 1] = e;
		for (int l = 0; l < 10; ++l){
			if (l == d)
				continue;
			int det = l * e % m;
			for (int k = 0; k < m; ++k)
				f[j + 1][(k + det) % m] += f[j][k];
		}
		for (int k = 0; k < m; ++k)
			f[j + 1][k] %= MOD;//, printf("%d %d, %d\n", j + 1, k, f[j + 1][k]);
		e = e * 100 % m;
	}

	int ret = 0, cnt = 0;
	int i;
	for (i = n - 1; i >= 0; i -= 2){
		--j;
		for (int k = 0; k < s[i] - '0'; ++k)
			if (k != d)
				ret = (ret + f[j][(m * 2 - cntd - k * g[j + 1] % m) % m]) % MOD;
		cntd = (cntd + (s[i] - '0') * g[j + 1]) % m;
		if (s[i] - '0' == d)
			break;
		if (i > 0){
			int t = s[i - 1] - '0';
			if (t < d)
				break;
			else if (t > d){
				ret = (ret + f[j][(m - cntd) % m]) % MOD;
				break;
			}
		}
	}
	if (i < 0 && cntd == 0)
		ret = (ret + 1) % MOD;
	return ret;
}

int main(){
	scanf("%d%d", &m, &d);
	scanf("%s%s", a, b);
	n = strlen(a);
	reverse(a, a + n);
	for (int i = 0; i < n; ++i)
		if (a[i] == '0')
			a[i] = '9';
		else{
			--a[i];
			break;
		}
	reverse(b, b + n);
	printf("%d\n", (count(b) + MOD - count(a)) % MOD);
	return 0;
}