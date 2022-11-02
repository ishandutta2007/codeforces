#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define inf 1e12
#define ep 1e-9
#define mp make_pair
#define pb push_back
#define ll long long
template<class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template<class T> void chkmin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> pii;

int n, k, a[N];
ll dp[2][N];
ll *A, *B;

struct movseg{
	int l, r, gas[N];
	ll sum;
	void init() {
		l = r = 1, sum = 0;
		memset(gas, 0, sizeof gas);
		gas[a[1]] = 1;
	}
	void leftex() {
		l --;
		sum += gas[a[l]]; gas[a[l]] ++;
	}

	void rightex() {
		r ++;
		sum += gas[a[r]]; gas[a[r]] ++;
	}
	void leftde() {
		gas[a[l]] --; sum -= gas[a[l]];
		l ++;
	}
	void rightde() {
		gas[a[r]] --; sum -= gas[a[r]];
		r --;
	}
} S;

ll func(int L, int R) {
	while (S.r < R) S.rightex();
	while (S.l > L) S.leftex();
	while (S.r > R) S.rightde();
	while (S.l < L) S.leftde();
	return S.sum;
}

void calc(int st, int en, int l, int r) {
	if (l > r) return;
	int m = l + r >> 1;
	int f = min(m - 1, en);
	ll tmp;
	B[m] = inf;
	for (int i = min(m - 1, en); i >= st; i --) {
		tmp = A[i] + func(i + 1, m);
		if (B[m] > tmp) {
			B[m] = tmp;
			f = i;
		}
	}
	calc(st, f, l, m - 1);
	calc(f, en, m + 1, r);
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++) scanf("%d", a + i);
	dp[0][0] = 0;
	for (int i = 1; i <= n; i ++) dp[0][i] = inf;
	for (int i = 1; i <= k; i ++) {
		A = dp[(i-1)%2], B = dp[i%2];
		S.init();
		calc(0, n, 0, n);
	}
	cout<<dp[k%2][n];
    return 0;
}