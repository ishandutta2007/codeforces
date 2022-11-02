#include <bits/stdc++.h>
using namespace std;

#define N 200020

int arr[N], n, Ql, Qr, l, r;
long long sum, ans;

int main(){
	///freopen("a.in", "r", stdin);
	scanf("%d %d %d %d %d", &n, &l, &r, &Ql, &Qr);

	ans = 1ll << 62;

	for(int i = 1; i <= n; i ++){
		scanf("%d", arr + i);
		sum += 1ll * l * arr[i];
	}

	sum += 1ll * Ql * (n - 1);

	ans = min(ans, sum);

	for(int i = 1; i <= n; i ++){
		int a = max(n - 2 * i + 1, 0) - max(n - 2 * i - 1, 0);
		int b = max(2 * i - n - 1, 0) - max(2 * i - n - 3, 0);
		sum -= 1ll * a * Ql;
		sum += 1ll * b * Qr;
		sum += 1ll * arr[n + 1 - i] * (r - l);
		ans = min(ans, sum);
	}
	cout << ans << endl;
}