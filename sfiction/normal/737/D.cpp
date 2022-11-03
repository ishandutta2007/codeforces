#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MAXN = 4E3 + 10, MAXM = 1E2;
const int BIAS = 0x3f3f3f3f;

int n;
int a[MAXN];
int f[MAXN / 2 + MAXM][MAXM << 1][MAXM][2];

int calc(int l, int r, int k, int p){
	int &s = f[l][l - r + MAXM][k][p];
	if (s)
		return s - BIAS;

	if (l + r + k > n)
		s = 0;
	else{
		if (p){
			s = calc(l + k, r, k, p ^ 1) + (a[l + k] - a[l]);
			if (l + r + k < n)
				s = max(s, calc(l + k + 1, r, k + 1, p ^ 1) + (a[l + k + 1] - a[l]));
		}
		else{
			s = calc(l, r + k, k, p ^ 1) - (a[n - r] - a[n - (r + k)]);
			if (l + r + k < n)
				s = min(s, calc(l, r + k + 1, k + 1, p ^ 1) - (a[n - r] - a[n - (r + k + 1)]));
		}
	}

	return (s += BIAS) - BIAS;
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i), a[i] += a[i - 1];
	printf("%d\n", calc(0, 0, 1, 1));
	return 0;
}