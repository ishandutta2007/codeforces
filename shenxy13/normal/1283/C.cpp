#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int f[n], g[n], ans[n];
	fill_n(g, n, 0);
	for (int i = 0; i < n; ++i) scanf("%d", &f[i]);
	for (int i = 0; i < n; ++i) {
		if (f[i]) ans[i] = f[i];
	}
	for (int i = 0; i < n; ++i) {
		if (f[i]) g[f[i] - 1] = i + 1;
	}
	vector<int> fless;
	for (int i = 0; i < n; ++i) {
		if (g[i] == 0 && f[i] == 0) fless.push_back(i);
	}
	if (fless.size() != 1) {
		for (int i = 0; i < fless.size(); ++i) ans[fless[i]] = fless[(i + 1) % fless.size()] + 1;
		fless.clear();
	}
	for (int i = 0; i < n; ++i) {
		if (g[i] == 0 && f[i] != 0) {
			int j = i;
			for (; f[j]; j = f[j] - 1);
			if (!fless.empty()) {
				ans[j] = fless[0] + 1;
				ans[fless[0]] = i + 1;
				fless.clear();
			} else ans[j] = i + 1;
		}
	}
	for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
	return 0;
}