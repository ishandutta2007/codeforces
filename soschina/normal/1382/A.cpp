#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1001;

int t, n, m, x, ans;
bool vis[N];

int main(){
	scanf("%d", &t);
	while(t--){
		ans = 0;
		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &n, &m);
		while(n--){
			scanf("%d", &x);
			vis[x] = true;
		}
		while(m--){
			scanf("%d", &x);
			if(vis[x]) ans = x;
		}
		if(ans) printf("YES\n1 %d\n", ans);
		else puts("NO");
	}
	return 0;
}