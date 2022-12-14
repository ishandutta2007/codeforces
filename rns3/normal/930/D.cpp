#include <bits/stdc++.h>
using namespace std;

#define N 101010

const int K = 100000;

typedef pair <int, int> pii;

int mnle[N*2], mxle[N*2], mnri[N*2], mxri[N*2];

struct problem {
	int n;
	pii p[N];
	void init() {
		n = 0;
	}

	void insert(int x, int y) {
		p[++n] = make_pair(x, y);
	}

	long long solve() {
		if (n < 4) return 0;
		sort(p + 1, p + n + 1);
		int m = 1;
		int mn = K, mx = -K;
		for (int k = -K; k <= K; k ++) {
			while (m <= n && p[m].first == k) {
				mn = min(mn, p[m].second);
				mx = max(mx, p[m].second);
				m ++;
			}
			mnle[k+N] = mn;
			mxle[k+N] = mx;
		}

		reverse(p + 1, p + n + 1);
		m = 1;
		mn = K, mx = -K;
		for (int k = K; k >= -K; k --) {
			while (m <= n && p[m].first == k) {
				mn = min(mn, p[m].second);
				mx = max(mx, p[m].second);
				m ++;
			}
			mnri[k+N] = mn;
			mxri[k+N] = mx;
		}

		long long rlt = 0;
		for (int k = -K + 1; k <= K; k ++) rlt += max(0, min(mxle[k-1+N], mxri[k+N]) - max(mnle[k-1+N], mnri[k+N]));
		return rlt;
	}
} P[2];

int main() {
	//freopen("r.in", "r", stdin);
	int n;
	scanf("%d", &n);
	P[0].init(), P[1].init();
	for (int i = 1, x, y, u, v; i <= n; i ++) {
		scanf("%d %d", &x, &y);
		int z = ((x + y) % 2 + 2) & 1;
		u = (x + y + z) / 2;
		v = (x - y + z) / 2;
		P[z].insert(u, v);
	}
	printf("%I64d\n", P[0].solve() + P[1].solve());

	return 0;
}