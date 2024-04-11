#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1E5 + 10;

ll a[MAXN][3];
ll f[MAXN][5];

int main(){
	int n;
	scanf("%d", &n);
	for (int j = 0; j < 3; ++j)
		for (int i = 1; i <= n; ++i)
			scanf("%lld", a[i] + j);
	f[0][0] = 0;
	f[0][1] = f[0][2] = f[0][3] = f[0][4] = -(1ll << 60);
	for (int i = 1; i <= n; ++i){
		f[i][0] = a[i][0] + max(f[i - 1][0], a[i][1] + max(f[i - 1][1], f[i - 1][2] + a[i][2]));
		f[i][1] = a[i][1] + max(f[i - 1][1], max(f[i - 1][0] + a[i][0], f[i - 1][2] + a[i][2]));
		f[i][2] = a[i][2] + max(f[i - 1][2], a[i][1] + max(f[i - 1][1], f[i - 1][0] + a[i][0]));
		f[i][3] = a[i][0] + a[i][1] + a[i][2] + max(f[i - 1][3], f[i - 1][0]);
		f[i][4] = a[i][0] + a[i][1] + a[i][2] + max(f[i - 1][4], f[i - 1][2]);

		f[i][0] = max(f[i][0], f[i - 1][4] + a[i][0] + a[i][1] + a[i][2]);
		f[i][2] = max(f[i][2], f[i - 1][3] + a[i][0] + a[i][1] + a[i][2]);
	}
	printf("%lld\n", f[n][2]);
	return 0;
}