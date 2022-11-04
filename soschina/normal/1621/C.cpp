#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e4 + 1;

int t, n, a[N], p[N], len;
bool vis[N];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		memset(vis + 1, 0, sizeof(bool) * n);
		for(int i = 1; i <= n; i++) if(!vis[i]){
			len = 0;
			do{
				printf("? %d\n", i);
				fflush(stdout);
				scanf("%d", &a[++len]);
				if(a[len] == 0) return 0;
				vis[a[len]] = true;
				if(len > 1) p[a[len - 1]] = a[len];
			}while(len == 1 || a[len] != a[1]);
		}
		putchar('!');
		for(int i = 1; i <= n; i++)
			printf(" %d", p[i]);
		putchar('\n');
		fflush(stdout);
	}
	return 0;
}