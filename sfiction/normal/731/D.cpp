#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 5E5 + 10, MAXC = 1E6 + 10;

int n, C;
vector<int> a[MAXN];
int tot, cnt[MAXC];

inline void mark(int l, int r){
	if (l == r)
		return;
	++tot;
	if (l < r){
		++cnt[0], --cnt[C - r];
		++cnt[C - l], --cnt[C];
	}
	else
		++cnt[C - l], --cnt[C - r];
}

bool solve(int l, int r, int d){
	int l0 = l;
	for (; l0 < r && a[l0].size() == d; ++l0);
	for (int i = l0 + 1; i < r; ++i)
		if (a[i].size() == d)
			return false;
	int pre = l0;
	bool flag = true;
	for (int i = l0 + 1; i < r; ++i)
		if (a[i - 1][d] != a[i][d]){
			mark(a[i - 1][d], a[i][d]);
			flag &= solve(pre, i, d + 1);
			pre = i;
		}
	if (pre < r)
		flag &= solve(pre, r, d + 1);
	return flag;
}

int main(){
	scanf("%d%d", &n, &C);
	for (int m, t, i = 0; i < n; ++i){
		scanf("%d", &m);
		for (int j = 0; j < m; ++j){
			scanf("%d", &t);
			a[i].push_back(t - 1);
		}
	}
	bool flag = solve(0, n, 0);
	if (!flag){
		puts("-1");
		return 0;
	}
	int ans = cnt[0] == tot ? 0 : -1;
	for (int i = 1; ans == -1 && i < C; ++i)
		if ((cnt[i] += cnt[i - 1]) == tot)
			ans = i;
	printf("%d\n", ans);
	return 0;
}