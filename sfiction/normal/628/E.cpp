#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 3E3 + 10;

int n, m;
char s[MAXN][MAXN];

int left[MAXN][MAXN], diag[MAXN][MAXN];
vector<int> E[MAXN];

int sum[MAXN];

inline int lowbit(int x){
	return x & (x ^ x - 1);
}

void update(int i){
	for (; i <= n; i += lowbit(i))
		++sum[i];
}

int query(int i){
	int ret = 0;
	for (; i > 0; i -= lowbit(i))
		ret += sum[i];
	return ret;
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);
	for (int i = n; i >= 1; --i)
		for (int j = 1; j <= m; ++j){
			if (s[i][j] == 'z')
				left[i][j] = left[i][j - 1] + 1, diag[i][j] = diag[i + 1][j - 1] + 1;
		}
	long long ans = 0;
	for (int j = 1; j <= m; ++j){
		for (int i = 1; i <= n; ++i)
			E[i].clear();
		for (int i = 1; i <= n; ++i)
			if (left[i][j] >= i)
				E[1].push_back(i);
			else
				E[i - left[i][j] + 1].push_back(i);
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= n; ++i){
			for (int k = 0; k < E[i].size(); ++k)
				update(E[i][k]);//, printf("%d %d %d\n", j, i, E[i][k]);
			int l = min(left[i][j], diag[i][j]);
			ans += query(i + l - 1) - query(i - 1);
//			printf("%d\n", ans);
		}
	}
	printf("%I64d\n", ans);
	return 0;
}