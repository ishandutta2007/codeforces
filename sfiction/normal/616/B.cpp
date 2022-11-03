#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int ans = -1;
	for (int i = 0; i < n; ++i){
		int v = 1E9;
		for (int t, j = 0; j < m; ++j){
			scanf("%d", &t);
			v = min(v, t);
		}
		ans = max(ans, v);
	}
	printf("%d\n", ans);
	return 0;
}