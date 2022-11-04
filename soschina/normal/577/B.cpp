#include <cstdio>
using namespace std;
const int MAXN = 1e3 + 1;

int n, m, num;
bool vis[2][MAXN];

int main(){
	scanf("%d%d", &n, &m);
	if(n >= m){
		printf("YES");
		return 0;
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &num);
		vis[i & 1][num % m] = true;
		for(int j = 0; j < m; j++) if(vis[(i & 1) ^ 1][j]){
			vis[i & 1][j] = true;
			vis[i & 1][(num + j) % m] = true;
		}
		if(vis[i & 1][0]){
			printf("YES");
			return 0;
		}
	}
	printf("NO");
	return 0;
}