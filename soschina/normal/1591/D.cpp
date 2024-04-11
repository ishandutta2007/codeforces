#include <cstdio>
#include <cstring>
#define lowbit(i) (i&-i)
using namespace std;
const int N = 5e5 + 1;

int t, n, a[N];
bool vis[N];

int tree[N];
void add(int i){
	i = n - i + 1;
	while(i <= n){
		tree[i]++;
		i += lowbit(i);
	}
}
int query(int i){
	i = n - i + 1;
	int ret = 0;
	while(i){
		ret += tree[i];
		i -= lowbit(i);
	}
	return ret;
}

int main(){
	scanf("%d", &t);
	while(t--){
		bool dup = false;
		memset(vis + 1, 0, sizeof(bool) * n);
		memset(tree + 1, 0, sizeof(int) * n);
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			if(vis[a[i]]) dup = true;
			else vis[a[i]] = true;
		}
		if(n == 1 || dup){
			puts("YES");
			continue;
		}
		long long ans = 0;
		for(int i = 1; i <= n; i++){
			ans += query(a[i]);
			add(a[i]);
		}
		puts((ans & 1) ? "NO" : "YES");
	}
	return 0;
}