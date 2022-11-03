#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 3E5 + 10;

int loc[MAXN];
vector<int> E[MAXN];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int t, i = 1; i <= n; ++i){
		scanf("%d", &t);
		loc[t] = i;
	}
	for (int l, r, i = 0; i < m; ++i){
		scanf("%d%d", &l, &r);
		l = loc[l], r = loc[r];
		if (l > r)
			swap(l, r);
		E[l].push_back(r);
	}
	ll ans = 0;
	int R = n + 1;
	for (int i = n; i >= 1; --i){
		for (int j = 0; j < E[i].size(); ++j)
			R = min(R, E[i][j]);
		ans += R - i;
	}
	printf("%I64d\n", ans);
	return 0;
}