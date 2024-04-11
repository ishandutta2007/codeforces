#include <cstdio>
using namespace std;

int t, n, m, a;

int main(){
	scanf("%d", &t);
	while(t--){
		bool ans = 1;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++){
				scanf("%d", &a);
				if(a > (i > 1) + (j > 1) + (i < n) + (j < m)) ans = 0;
			}
		if(ans){
			puts("YES");
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= m; j++)
					printf("%d ", (i > 1) + (j > 1) + (i < n) + (j < m));
				putchar('\n');
			}
		}else puts("NO");
	}
	return 0;
}