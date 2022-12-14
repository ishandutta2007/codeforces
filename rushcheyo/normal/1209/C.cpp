#include <bits/stdc++.h>
using namespace std;

int T, n, foo;
vector<int> fst, lst;
char d[200005], ans[200005];

bool check(int x, vector<int> fst, vector<int> lst) {
	int pre = -1;
	for (int i = 0; i < x; ++i)
		if (fst[i] != -1) {
			if (pre != -1 && fst[i] < pre) return false;
			pre = lst[i];
		}
	lst[x] = -1;
	for (int i = 1; i <= pre; ++i)
		if (d[i] == '0' + x) lst[x] = i;
	foo = pre;
	pre = lst[x];
	for (int i = x + 1; i < 10; ++i)
		if (fst[i] != -1) {
			if (pre != -1 && fst[i] < pre) return false;
			pre = lst[i];
		}
	return true;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%s", &n, d + 1);
		fst.resize(10), lst.resize(10);
		for (int i = 0; i < 10; ++i) fst[i] = lst[i] = -1;
		for (int i = 1; i <= n; ++i) lst[d[i] - '0'] = i;
		for (int i = n; i; --i) fst[d[i] - '0'] = i;
		bool flag = false;
		for (int i = 0; i <= 9; ++i)
			if (check(i, fst, lst)) {
				flag = true;
				for (int j = 1; j <= n; ++j)
					if (d[j] < '0' + i) ans[j] = '1';
					else if (d[j] > '0' + i) ans[j] = '2';
					else if (j <= foo) ans[j] = '2';
					else ans[j] = '1';
				ans[n + 1] = 0;
				puts(ans + 1);
				break;
			}
		if (!flag) puts("-");
	}
}