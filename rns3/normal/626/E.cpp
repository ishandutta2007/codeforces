#include <bits/stdc++.h>
using namespace std;

#define N 202020

int n, a[N];

long long s[N];

double ans = 0, now;
const long double wahaha = 1;
int st, en, mid, stt = 0, kk = 1;

void solve(int k) {
    en = min(k - 1, n - k);
    st = 1;
    while (st < en) {
		mid = (st + en + 1) >> 1;
		if ((s[mid] + s[k+mid] - s[k-1]) * (mid * 2 - 1) > (s[mid-1] + s[k+mid-1] - s[k-1]) * (mid * 2 + 1)) st = mid;
		else en = mid - 1;
    }
    now = wahaha * (s[st] + s[k+st] - s[k-1]) / (st * 2 + wahaha) - a[k];
    if (ans < now) ans = now, stt = st, kk = k;
}

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	sort (a + 1, a + n + 1);
	for (int i = 1; i * 2 <= n; i ++) swap(a[i], a[n+1-i]);
    for (int i = 1; i <= n; i ++) s[i] = s[i-1] + a[i];
    for (int i = 2; i < n; i ++) solve(i);
    printf("%d\n", stt * 2 + 1);
    for (int i = 1; i <= stt; i ++) printf("%d ", a[i]);
    for (int i = kk; i <= kk + stt; i ++) printf("%d ", a[i]);
    puts("");

	return 0;
}