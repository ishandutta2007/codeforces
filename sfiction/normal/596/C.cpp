#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 1E5 + 10, MAXW = 1E5 + 10;

int x[MAXN], y[MAXN];
int w[MAXN], b[MAXN];
int cnt[MAXW << 1 | 1];
vector<int> lst[MAXW << 1 | 1], coor[MAXW];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d%d", &x[i], &y[i]);
		++cnt[MAXW + y[i] - x[i]];
		coor[x[i]].push_back(0);
	}
	bool flag = true;
	for (int i = 0; i < n; ++i){
		scanf("%d", &w[i]);
		flag &= --cnt[MAXW + w[i]] >= 0;
		lst[MAXW + w[i]].push_back(i);
	}
	if (!flag){
		puts("NO");
		return 0;
	}

	for (int i = 0; i < n; ++i)
		b[coor[x[i]][y[i]] = lst[MAXW + y[i] - x[i]][min(x[i], y[i])]] = i;
	bool ans = true;
	for (int i = 0; i < n; ++i)
		ans &= (x[i] == 0 || coor[x[i] - 1][y[i]] < coor[x[i]][y[i]]) && (y[i] == 0 || coor[x[i]][y[i] - 1] < coor[x[i]][y[i]]);
	if (ans){
		puts("YES");
		for (int i = 0; i < n; ++i)
			printf("%d %d\n", x[b[i]], y[b[i]]);
	}
	else
		puts("NO");
	return 0;
}