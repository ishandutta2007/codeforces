#include <bits/stdc++.h>
using namespace std;

int a[1000001];

int main() {
	///freopen("1.in", "r", stdin);
	int n, h, k;
	scanf("%d %d %d", &n, &h, &k);
	for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    int st = 1, r = 0;
    long long ans = 0;
    while(st <= n) {
        while(st < n + 1 && r + a[st] <= h) r += a[st], st ++;
		if(r < k) ans ++, r = 0;
		ans += r / k;
		r %= k;
    }
    ans += (r + k - 1) / k;
	cout << ans << endl;
}