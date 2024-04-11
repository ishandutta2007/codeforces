#include <bits/stdc++.h>

using namespace std;
int n, m;

#define maxn 100010
#define add sqrtsqrt
int ans[maxn];

struct query {
	int block;
	int l;
	int r;
	int ind;

	bool operator < (const query& o) {
		if (block != o.block) {
			return block < o.block;
		}
		return r < o.r;
	}
};

int nums[maxn];
vector<query> qus;
int cans = 0;
int freq[maxn]; //set all to zero

void add(int u) {
	// cout << u << ": " << freq[u] << endl;
	if (u > n) return;
	if (freq[u] == u) cans--;
	freq[u]++;
	if (freq[u] == u) cans++;
}
void rem(int u) {
	if (u > n) return;
	if (freq[u] == u) cans--;
	freq[u]--;
	if (freq[u] == u) cans++;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	int lc, rc;
	for (int i = 0; i < m; i++) {
		cin >> lc >> rc;
		int bc = lc / sqrt(n);
		query qc;
		qc.l = lc;
		qc.r = rc;
		qc.block = bc;
		qc.ind = i;
		qus.push_back(qc);
	}

	sort(qus.begin(), qus.end());

	int lt = qus[0].l;
	int rt = qus[0].r;
	for (int i = lt; i <= rt; i++) {
		add(nums[i]);
	}
	ans[qus[0].ind] = cans;
	for (int i = 1; i < m; i++) {
		int nl = qus[i].l;
		int nr = qus[i].r;
		while (rt < nr) {
			rt++;
			add(nums[rt]);
		}
		while (lt > nl) {
			lt--;
			add(nums[lt]);
		}
		while (rt > nr) {
			rem(nums[rt]);
			rt--;
		}
		while (lt < nl) {
			rem(nums[lt]);
			lt++;
		}
		ans[qus[i].ind] = cans;

	}
	for (int i  = 0; i < m; i++) {
		cout << ans[i] << '\n';
	}
	cout.flush();

}