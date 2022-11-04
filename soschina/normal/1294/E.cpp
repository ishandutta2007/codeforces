#include <cstdio>
#include <vector>
using namespace std;

int n, m, x, ans;

int main(){
	scanf("%d%d", &n, &m);
	vector<vector<int>> cnt(m, vector<int>(n, n));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			scanf("%d", &x);
			--x;
			if(x < n * m && (x - j) % m == 0)
				cnt[j][(i - (x - j) / m + n) % n]--;
		}
	for(int j = 0; j < m; j++){
		int tmp = n;
		for(int i = 0; i < n; i++)
			tmp = min(tmp, i + cnt[j][i]);
		ans += tmp;
	}
	printf("%d", ans);
	return 0;
}