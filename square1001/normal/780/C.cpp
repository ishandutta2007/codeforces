#include <cstdio>
#include <vector>
using namespace std;
int n, x, y, a[200009], ret; vector<int> g[200009];
void solve(int pos, int pre) {
	int cnt = 0;
	for (int i : g[pos]) {
		if (i == pre) continue; cnt++;
		while (a[pos] == cnt || (pre != -1 && a[pre] == cnt)) cnt++;
		a[i] = cnt;
		solve(i, pos);
	}
	ret = ret > cnt ? ret : cnt;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &x, &y); x--, y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	a[0] = 1; solve(0, -1);
	printf("%d\n", ret);
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	return 0;
}