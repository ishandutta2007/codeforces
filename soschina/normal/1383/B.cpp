#include <cstdio>
#include <cstring>
using namespace std;

int t, n, x, cnt[31], i;

int main(){
	scanf("%d", &t);
	while(t--){
		memset(cnt, 0, sizeof(cnt));
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d", &x);
			for(int j = 0; j < 31; j++)
				if(x & (1 << j)) ++cnt[j];
		}
		for(i = 30; ~i; i--) if(cnt[i] % 2){
			puts(cnt[i] % 4 == 3 && (n - cnt[i]) % 2 == 0 ? "LOSE" : "WIN");
			break;
		}
		if(i == -1) puts("DRAW");
	}
	return 0;
}