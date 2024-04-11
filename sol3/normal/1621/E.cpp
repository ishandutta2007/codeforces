#include <bits/stdc++.h>
using namespace std;

#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;

inline int qread() {
	register char c = getchar();
	register int x = 0, f = 1;
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - 48;
		c = getchar();
	}
	return x * f;
}

const int N = 200005;
int n, m, a[N], idx[N], st[21][N], sk;
long long sum[N];
long double avg[N];
vector <pair <int, int> > tmpb[N], b[N];
bool ans[N];

inline void Read() {
	n = qread(); m = qread();
	for (int i = 1;i <= n;i++) a[i] = qread();
	sk = 0;
	for (int i = 1;i <= m;i++) {
		tmpb[i].clear();
		int k = qread();
		while (k--) tmpb[i].push_back(make_pair(qread(), ++sk));
	}
	for (int i = 1;i <= sk;i++) ans[i] = 0;
}

inline bool cmp(int i, int j) {
	return avg[i] > avg[j];
}

inline void Prefix() {
	sort(a + 1, a + n + 1, greater <int>());
	for (int i = 1;i <= m;i++) {
		sum[i] = 0;
		for (int j = 0;j < tmpb[i].size();j++) sum[i] += tmpb[i][j].first;
		avg[i] = (long double)sum[i] / tmpb[i].size();
		idx[i] = i;
	}
	sort(idx + 1, idx + m + 1, cmp);
	for (int i = 1;i <= m;i++) {
		b[i].clear();
		for (int j = 0;j < tmpb[idx[i]].size();j++) b[i].push_back(tmpb[idx[i]][j]);
		sum[i] = 0;
		for (int j = 0;j < b[i].size();j++) sum[i] += b[i][j].first;
		sort(b[i].begin(), b[i].end(), greater <pair <int, int> >());
	}
	sort(avg + 1, avg + m + 1, greater <long double>());
}

inline int Query(int l, int r) {
	if (l > r) return 0x3f3f3f3f;
	int k = 31 - __builtin_clz(r - l + 1);
	return min(st[k][l], st[k][r - (1 << k) + 1]);
}

inline bool Check(int i, int mid) {
	long double navg = (long double)(sum[i] - b[i][mid].first) / (b[i].size() - 1);
	//cout << i << " " << mid << " " << sum[i] << " " << b[i][mid].first << " " << navg << " " << avg[i] << endl;
	if (navg >= avg[i]) {
		int idx = lower_bound(avg + 1, avg + m + 1, navg, greater <long double>()) - avg - 1;
		int k = upper_bound(a + 1, a + n + 1, (int)ceil(navg), greater <int>()) - a - 1;
		//cout << idx << " " << k << endl;
		if (Query(idx + 1, i - 1) >= 1 && Query(1, idx) >= 0 && Query(i + 1, m) >= 0 && k - (idx + 1) >= 0) return 1;
		return 0;
	} else {
		int idx = lower_bound(avg + 1, avg + m + 1, navg, greater <long double>()) - avg - 1;
		int k = upper_bound(a + 1, a + n + 1, (int)ceil(navg), greater <int>()) - a - 1;
		if (Query(i + 1, idx) >= -1 && Query(1, i - 1) >= 0 && Query(idx + 1, m) >= 0 && k - idx >= 0) return 1;
		return 0;
	}
}

inline void Solve() {
	for (int i = 0;i <= 20;i++) {
		for (int j = 1;j <= m;j++) {
			st[i][j] = 0x3f3f3f3f;
		}
	}
	for (int i = 1;i <= m;i++) {
		int k = upper_bound(a + 1, a + n + 1, (int)ceil(avg[i]), greater <int>()) - a - 1;
		st[0][i] = k - i;
		//cout << st[0][i] << " ";
	}
	//cout << endl;
	for (int i = 1;i <= 20;i++) {
		for (int j = 1;j <= m;j++) {
			if (j + (1 << i) - 1 > m) break;
			st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
		}
	}
	for (int i = 1;i <= m;i++) {
		int l = -1, r = b[i].size();
		while (l < r - 1) {
			int mid = l + r >> 1;
			if (Check(i, mid)) l = mid;
			else r = mid;
		}
		for (int j = 0;j <= l;j++) ans[b[i][j].second] = 1;
	}
	for (int i = 1;i <= sk;i++) cout << ans[i];
	cout << endl;
}

int main() {
	std::ios::sync_with_stdio(0);
	int t = qread();
	while (t--) {
		Read();
		Prefix();
		Solve();
	}
	cout.flush();
	#ifdef CFA_44
	while (1);
	#endif
	return 0;
}