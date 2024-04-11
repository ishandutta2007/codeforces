#include <bits/stdc++.h>
using namespace std;

deque <int> all[35010];
long long sum;
int a[35010];
long long f[35010], g[35010];
int cl = 1, cr = 0;

void AddLef(int x) {
	if (all[a[x]].size()) sum += all[a[x]].front() - x;
	all[a[x]].push_front(x);
}

void AddRig(int x) {
	if (all[a[x]].size()) sum -= all[a[x]].back() - x;
	all[a[x]].push_back(x);
}

void EraLef(int x) {
	all[a[x]].pop_front();
	if (all[a[x]].size()) sum -= all[a[x]].front() - x;
}

void EraRig(int x) {
	all[a[x]].pop_back();
	if (all[a[x]].size()) sum += all[a[x]].back() - x;
}

void Move(int l, int r) {
	while (cl > l) AddLef(--cl); 
	while (cr < r) AddRig(++cr);
	while (cl < l) EraLef(cl++);
	while (cr > r) EraRig(cr--);
}

void solve(int l, int r, int L, int R) {
	if (l > r) return ;
	int mid = l + r >> 1, p = -1;
	for (int i = L; i <= min(mid - 1, R); i++) {
		Move(i + 1, mid);
		if (g[mid] > f[i] + sum) g[mid] = f[i] + sum, p = i;
	}
	solve(l, mid - 1, L, p), solve(mid + 1, r, p, R);
}

int main() {
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	memset(f, 0x3f, sizeof(f)), f[0] = 0;
	for (int it = 0; it < k; it++) {
		memset(g, 0x3f, sizeof(g)), solve(1, n, 0, n - 1), swap(f, g);
	}
	cout << f[n] << endl;
	return 0;
}