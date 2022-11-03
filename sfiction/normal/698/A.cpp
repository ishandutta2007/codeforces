#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MAXN = 1E2 + 10;

int f[MAXN][3];

int main(){
	int n;
	scanf("%d", &n);
	f[0][0] = 0;
	for (int t, i = 1; i <= n; ++i){
		scanf("%d", &t);
		f[i][1] = f[i][2] = n + 1;
		f[i][0] = min(f[i - 1][0], min(f[i - 1][1], f[i - 1][2])) + 1;
		if (t & 1)
			f[i][1] = min(f[i - 1][0], f[i - 1][2]);
		if (t & 2)
			f[i][2] = min(f[i - 1][0], f[i - 1][1]);
	}
	printf("%d\n", min(f[n][0], min(f[n][1], f[n][2])));
	return 0;
}