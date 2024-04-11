#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define x first
#define y second

typedef pair <int, int> pii;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;

#define N 100010

int a[N], b[N];
ll s[N];
ll dp[N];
int n, c;

deque <int> dq;

void func() {
    int sz = 0;
    for (int i = 1; i <= n; i ++) {
		while (sz) {
			int j = dq.back();
			if (a[j] >= a[i]) dq.pop_back(), sz --;
			else break;
		}
		sz ++;
		dq.push_back(i);
		while (sz) {
			int j = dq.front();
			if (j <= i - c) dq.pop_front(), sz --;
			else break;
		}
		b[i] = a[dq.front()];
	}

}

int main() {
    scanf("%d %d", &n, &c);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i];
    func();
    for (int i = 1; i <= n; i ++) {
		dp[i] = dp[i - 1] + a[i];
		if (i >= c) dp[i] = min(dp[i - c] + s[i] - s[i - c] - b[i], dp[i]);
    }
	printf("%I64d\n", dp[n]);
	return 0;
}