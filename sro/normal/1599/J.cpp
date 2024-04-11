#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N;
int b[200005], ans[200005];
vector<int> ji, ou;
int tmp[30000005];
int sm[20005], sn[20005];

void solve(vector<int> &s) {
	int n = SZ(s);
	int n1 = n >> 1, n2 = n - n1;
	for (int i = 0; i < (1 << n1); ++i) {
		int ss = 0;
		for (int j = 0; j < n1; ++j) if ((i >> j) & 1) ss += s[j];
		sm[i] = ss;
	}
	for (int i = 0; i < (1 << n2); ++i) {
		int ss = 0;
		for (int j = 0; j < n2; ++j) if ((i >> j) & 1) ss += s[j + n1];
		sn[i] = ss;
	}
	int m1 = -1, m2 = -1;
	memset(tmp, -1, sizeof(tmp));
	for (int j = 0; j < (1 << n); ++j) if (__builtin_popcount(j) == n1) {
		int ss = sm[j & ((1 << n1) - 1)] + sn[j >> n1];
		if (~tmp[ss]) {
			m1 = tmp[ss], m2 = j;
			break;
		}
		tmp[ss] = j;
	}
	if (!~m1) puts("NO"), exit(0);
	int an = m1 & m2;
	m1 ^= an; m2 ^= an;
	vector<int> res, s1, s2;
	for (int i = 0; i < n; ++i) if ((m1 >> i) & 1) s1.push_back(s[i]);
	for (int i = 0; i < n; ++i) if ((m2 >> i) & 1) s2.push_back(s[i]);
	for (int i = 0; i < SZ(s1); ++i) res.push_back(s1[i]), res.push_back(s2[i]);
	int lst = 0; ans[1] = 0;
	for (int i = 0; i < SZ(res) - 1; ++i) ans[i + 2] = res[i] - lst, lst = ans[i + 2];
	int ptr = SZ(res);
	for (int i = 0; i < n; ++i) if (!((m1 >> i) & 1) && !((m2 >> i) & 1)) ans[++ptr] = s[i] - ans[1];
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", b + i);
		((b[i] & 1) ? ji : ou).push_back(b[i]);
	}
	if (SZ(ou)) {
		int a, b, c;
		if (SZ(ou) >= 3) tie(a, b, c) = make_tuple(ou[0], ou[1], ou[2]);
		else if (SZ(ji) >= 2) tie(a, b, c) = make_tuple(ou[0], ji[0], ji[1]);
		else return puts("NO"), 0;
		ans[1] = (a - b + c) >> 1;
		ans[2] = a - ans[1]; ans[3] = c - ans[1];
		int ptr = 3;
		if (SZ(ou) >= 3) {
			for (int i = 3; i < SZ(ou); ++i) ans[++ptr] = ou[i] - ans[1];
			for (int i = 0; i < SZ(ji); ++i) ans[++ptr] = ji[i] - ans[1];
		}
		else {
			for (int i = 1; i < SZ(ou); ++i) ans[++ptr] = ou[i] - ans[1];
			for (int i = 2; i < SZ(ji); ++i) ans[++ptr] = ji[i] - ans[1];
		}
		puts("YES");
		for (int i = 1; i <= N; ++i) printf("%d ", ans[i]);
		return 0;
	}
	vector<int> tmp;
	for (int i = 1; i <= min(N, 28); ++i) tmp.push_back(b[i]);
	solve(tmp);
	for (int i = min(N, 28) + 1; i <= N; ++i) ans[i] = b[i] - ans[1];
	puts("YES");
	for (int i = 1; i <= N; ++i) printf("%d ", ans[i]);
	return 0;
}