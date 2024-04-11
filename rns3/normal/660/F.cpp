#include <bits/stdc++.h>
using namespace std;
#define M 1000100
const int mod = 1000000007;
typedef long long ll;

int n;
ll a[M], T[M], S[M], U[M];
int m;
int q[M];

ll F(int i, int x) {
	return U[x] + x * S[i];
}
double G(int x, int y) {
	return 1. * (U[x] - U[y]) / (y - x);
}
void chkmax(ll &x, ll y) {
	if (x < y) {
		x = y;
	}
}

ll calc(int i) {
	ll s = F(i, q[1]);
    int mn = 1, mx = m;
    //for (int j = 1; j <= m; j++) printf("%I64d ", F(i, q[j])); puts("");
    while (mn < mx) {
        int mid = mx + mn >> 1;
		if (F(i, q[mid]) > F(i, q[mid+1])) {
			mn = mid + 1;
		} else {
			mx = mid;
		}
    }
    return min(s, F(i, q[mn]));
}

int main() {
	//freopen("A3.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%I64d", a + i);
		S[i] = S[i-1] + a[i];
		T[i] = T[i-1] + a[i] * i;
		U[i] = T[i] - S[i] * i;
		//printf("S[%d] = %I64d, T[%d] = %I64d, U[%d] = %I64d\n", i, S[i], i, T[i], i, U[i]);
	}

	ll rlt = 0;
	m = 1;
	q[1] = 0;
	for (int i = 1; i <= n; i++) {
		#ifdef u
		ll ttt = F(i, 1);
		for (int j = 0; j < i; j++) ttt = min(ttt, F(i, j));
		chkmax(rlt, T[i] - ttt);
		continue;
		#endif u

        ll tmp = calc(i);
        //ll tmp = F(i, 0);
        //for (int j = 1; j <= m; j++) tmp = min(tmp, F(i, q[j]));
        chkmax(rlt, T[i] - tmp);
		while (m > 1 && G(q[m-1], q[m]) <= G(q[m], i)) m--;
		q[++m] = i;
		//printf("i = %d, m = %d; q[%d] = %d\n", i, m, m-1, q[m-1]);
	}
	printf("%I64d\n", rlt);
	return 0;
}