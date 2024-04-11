#include <bits/stdc++.h>

using namespace std;

const int MAXN = 80;

int n;
vector<int> a[3];
int cnt[MAXN][3];
int f[MAXN][MAXN][MAXN][3];

int solve(int i, int j, int k, int last){
	if (i + j + k == 0)
		return 1;

	int b[3] = {i, j, k};
	if (b[last] <= 0)
		return INT_MAX;
	if (f[i][j][k][last])
		return f[i][j][k][last];

	int ret = INT_MAX >> 1;
	--b[last];
	for (int li = last == 1; li < 3; ++li)
		ret = min(ret, solve(b[0], b[1], b[2], li) - 1);

	int *loc = cnt[a[last][b[last]]];
	ret += abs(loc[0] - i) + abs(loc[1] - j) + abs(loc[2] - k);
//	printf("%d %d %d, %d = %d\n", i, j, k, last, ret);
	return f[i][j][k][last] = ret + 1;
}

char s[MAXN];

int main(){
	scanf("%d%s", &n, s + 1);
	for (int i = 1; i <= n; ++i){
		copy_n(cnt[i - 1], 3, cnt[i]);
		int t = s[i] == 'V' ? 0 : s[i] == 'K' ? 1 : 2;
		++cnt[i][t];
		a[t].push_back(i);
	}
	int ans = INT_MAX;
	for (int i = 0; i < 3; ++i)
		ans = min(ans, solve(a[0].size(), a[1].size(), a[2].size(), i));
	printf("%d\n", ans - 1 >> 1);
	return 0;
}