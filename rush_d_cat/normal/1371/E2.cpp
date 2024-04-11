#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100002;
int n, p, a[N], b[N], c[N];

int check(int x){
	for (int i = 0; i <= n; i ++) c[i] = 0;
	for (int i = 1; i <= n; i ++) {
		if (x >= a[i]) b[i] = n;
		else b[i] = n + (x - a[i]);
		// printf("b[%d] = %d\n", i, b[i]);
		if (b[i] <= 0) return 0;
	}
	for (int i = 1; i <= n; i ++) c[b[i]] ++;
	int id = 0;
	for (int i = 1; i <= n; i ++) while (c[i] --) b[++id] = i;
	for (int i = 1; i <= n; i ++) {
		if (b[i] - (i-1) <= 0) return 0;
	}
	return 1;
}

int mx[N];
void tag(int pos, int val) {
	// show all value in range [0, pos] % p = val
	mx[val] = max(mx[val], pos);
}

bool flag[N];
void output_sol(int from) {
	for (int i = 0; i < p; i ++) {
		// printf("i = %d, mx = %d\n", i, mx[i]);
		if (mx[i] == -1) continue;
		for (int j = i; j <= mx[i]; j += p) {
			flag[j] = 1;
		}
	}

	int mxdet = 0;
	for (int i = 1; i <= n; i ++) mxdet = max(mxdet, n - b[i]);
	vector<int> v;
	int lim = 1e9;
	for (int i = 1; i <= n; i ++) {
		if ((n - (i - 1)) % p == 0) {
			lim = min(lim, n - b[i] - 1);
		}
	}

	for (int i = 0; i <= mxdet; i ++) {
		//printf("# %d\n", from + i);
		if (flag[i] == 0 && i <= lim) v.push_back(from + i);
	}
	printf("%d\n", v.size());
	for (auto x: v) printf("%d ", x);
}

void gen(int x) {
	for (int i = 1; i <= n; i ++) {
		if (x >= a[i]) b[i] = n;
		else b[i] = n + (x - a[i]);
	}
	sort(b + 1, b + 1 + n);
	for (int i = 1; i <= n; i ++) {
		int cur = b[i] - (i-1);
		//printf("i = %d, b = %d, cur = %d\n", i, b[i], cur);
		//printf("tag %d %d\n", n - b[i], (- cur % p + p) % p);
		tag(n - b[i], (- cur % p + p) % p );
	}
}
int main() {
	memset(mx, -1, sizeof(mx));
	scanf("%d%d",&n,&p);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	// check(3); return 0;
	int lef = 0, rig = 1e9;
	while (rig - lef > 1) {
		int mid = (lef + rig) >> 1;
		if (check(mid)) rig = mid;
		else lef = mid;
	}
	//printf("rig = %d\n", rig);
	gen(rig);
	output_sol(rig);
}