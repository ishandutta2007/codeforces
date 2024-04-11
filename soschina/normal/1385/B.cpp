#include <cstdio>
#include <cstring>
using namespace std;

int t, n, x;
bool vis[51];

int main(){
	scanf("%d", &t);
	while(t--){
		memset(vis + 1, 0, sizeof(bool) * n);
		scanf("%d", &n);
		for(int i = 1; i <= n * 2; i++){
			scanf("%d", &x);
			if(!vis[x]){
				printf("%d ", x);
				vis[x] = true;
			}
		}
		putchar('\n');
	}
	return 0;
}