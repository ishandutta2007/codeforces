#include <cstdio>
#include <map>

using namespace std;

int rd() {
	int x = 0, f = 1; char c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

const int N = 3e5 + 10;
const int inf = 1e6 + 10;
map <int, int> mp;
int a[N], s1[N], s2[N], sum[N << 2], tag[N << 2];
int L, R, ans, n, K, d, top1, top2, k;


void modify(int k, int l, int r, int x, int y, int z) {
	if (x == l && r == y) {
		sum[k] += z, tag[k] += z;
		return;
	}
	int mid = l + r >> 1;
	if (y <= mid) modify(k << 1, l, mid, x, y, z);
	else if (x > mid) modify(k << 1 | 1, mid + 1, r, x, y, z);
	else modify(k << 1, l, mid, x, mid, z), modify(k << 1 | 1, mid + 1, r, mid + 1, y, z);
	tag[k] = min(tag[k << 1], tag[k << 1 | 1]) + sum[k];
}

int query(int k, int l, int r, int x) {
	if (l == r) return l;
	int mid = l + r >> 1; x -= sum[k];
	if (tag[k << 1] <= x) return query(k << 1, l, mid, x);
	else return query(k << 1 | 1, mid + 1, r, x);
}

int main() {
	n = rd(), K = rd(), d = rd();
	for (int i = 1; i <= n; i ++) a[i] = rd() + 1e9 + 1;
	L = R = ans = 1;
	if (!d) {
		for (int j, i = 1; i <= n; i = j + 1) {
			for (j = i; j < n && a[j + 1] == a[i]; j ++);
			if (j - i + 1 > ans) ans = j - i + 1, L = i, R = j;
		}
		return printf("%d %d\n", L, R), 0;
	}
	modify(1, 1, n, 1, n, inf);
	for (int i = 1; i <= n; i ++) {
		if (i != 1 && (a[i] - a[i - 1]) % d) modify(1, 1, n, k + 1, i - 1, inf), k = i - 1;
		if (mp[a[i]] > k) modify(1, 1, n, k + 1, mp[a[i]], inf), k = mp[a[i]];
		mp[a[i]] = i;
		while (top1 && a[s1[top1]] > a[i]) modify(1, 1, n, s1[top1 - 1] + 1, s1[top1], a[s1[top1]] / d - a[i] / d), top1 --;
		while (top2 && a[s2[top2]] < a[i]) modify(1, 1, n, s2[top2 - 1] + 1, s2[top2], a[i] / d - a[s2[top2]] / d), top2 --;		
		s1[++top1] = s2[++top2] = i;
		modify(1, 1, n, i, i, i - inf);
		int j = query(1, 1, n, i + K);
		if (i + L > R + j) L = j, R = i;
	}
	return printf("%d %d\n", L, R), 0;
}