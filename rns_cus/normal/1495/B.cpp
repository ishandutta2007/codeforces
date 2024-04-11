#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << H << ' ';
	debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 0
#endif

#define N 100100

int n, p[N], le[N][2], ri[N][2];
int pre[N], suf[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &p[i]);
    le[1][0] = le[1][1] = 1, ri[n][0] = ri[n][1] = n;
    for (int i = 2; i <= n; i ++) {
		le[i][0] = le[i][1] = i;
		if (p[i] < p[i-1]) le[i][0] = le[i-1][0];
		else le[i][1] = le[i-1][1];
    }
    for (int i = n - 1; i >= 1; i --) {
		ri[i][0] = ri[i][1] = i;
		if (p[i] < p[i+1]) ri[i][0] = ri[i+1][0];
		else ri[i][1] = ri[i+1][1];
    }
    for (int i = 1; i <= n; i ++) pre[i] = max(pre[i-1], max(i - le[i][0], ri[i][0] - i));
    for (int i = n; i >= 1; i --) suf[i] = max(suf[i+1], max(i - le[i][0], ri[i][0] - i));
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
		int L = le[i][1], R = ri[i][1];
		if (L == i || R == i) continue;
		if (max(pre[L-1], suf[R+1]) >= max(i - L, R - i)) continue;
		if (max(L - le[L][0], ri[R][0] - R) >= max(i - L, R - i)) continue;
		int x = i - L, y = R - i;
		if (x < y) swap(x, y);
		if (!(x & 1)) x --;
		if (x >= y) continue;
		ans ++;
    }
    printf("%d\n", ans);

    return 0;
}