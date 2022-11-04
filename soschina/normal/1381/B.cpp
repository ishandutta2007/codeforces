#include <cstdio>
#include <cstring>
using namespace std;
const int N = 2001;

int t, n, cnt, x, y;
bool vis[N];

int main(){
	vis[0] = 1;
	scanf("%d", &t);
	while(t--){
		memset(vis + 1, 0, sizeof(bool) * n);
		scanf("%d", &n);
		cnt = y = 0;
		for(int i = 1; i <= 2 * n; i++){
			scanf("%d", &x);
			if(x > y){
				for(int j = n; j >= cnt; j--)
					if(vis[j - cnt]) vis[j] = true;
				cnt = 0;
				y = x;
			}
			++cnt;
		}
		for(int j = n; j >= cnt; j--)
			if(vis[j - cnt]) vis[j] = true;
		puts(vis[n] ? "YES" : "NO");
	}
	return 0;
}