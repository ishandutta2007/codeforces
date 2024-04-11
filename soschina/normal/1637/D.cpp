#include <cstdio>
#include <cstring>
using namespace std;
const int N = 101, M = 10001;

int t, n, a[N], b[N];
bool vis[N][M] = {1};

int main(){
	scanf("%d", &t);
	while(t--){
		memset(vis + 1, 0, sizeof(bool) * M * n);
		scanf("%d", &n);
		int sum = 0;
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			sum += a[i];
		}
		for(int i = 1; i <= n; i++){
			scanf("%d", &b[i]);
			sum += b[i];
		}
		int m = sum / 2;
		for(int i = 1; i <= n; i++){
			for(int j = a[i]; j <= m; j++)
				vis[i][j] = vis[i - 1][j - a[i]];
			for(int j = b[i]; j <= m; j++)
				if(!vis[i][j]) vis[i][j] = vis[i - 1][j - b[i]];
		}
		for(int i = m; i > 0; i--){
			if(vis[n][i]){
				m = i;
				break;
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++)
			ans += a[i] * a[i] + b[i] * b[i];
		ans *= n - 2;
		printf("%d\n", ans + m * m + (sum - m) * (sum - m));
	}
	return 0;
}