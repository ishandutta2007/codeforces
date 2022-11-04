#include <cstdio>
#include <cstring>
using namespace std;
const int N = 2e5 + 1;

int t, n;
bool vis[N];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		memset(vis + 1, 0, sizeof(bool) * n);
		puts("2");
		for (int i = 1; i <= n; i++) if(!vis[i]){
				for (int j = i; j <= n; j *= 2){
					vis[j] = true;
					printf("%d ", j);
				}
		}
		putchar('\n');
	}
	return 0;
}