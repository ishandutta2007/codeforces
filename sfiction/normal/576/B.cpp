#include <cstdio>

const int MAXN = 1E5 + 10;

int a[MAXN];
bool vis[MAXN];

int main(){
	int n, center = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		if (a[i] == i)
			center = i;
	}
	if (center){
		puts("YES");
		for (int i = 1; i <= n; ++i)
			if (i != center)
				printf("%d %d\n", center, i);
	}
	else{
		int u = 0;
		bool even = true;
		for (int i = 1; i <= n; ++i)
			if (!vis[i]){
				int cnt = 0;
				for (int t = i; !vis[t]; t = a[t], ++cnt)
					vis[t] = true;
				if (cnt & 1){
					even = false;
					break;
				}
				else if (cnt == 2)
					u = i;
			}
		if (even && u){
			puts("YES");
			printf("%d %d\n", u, a[u]);
			vis[u] = vis[a[u]] = false;
			for (int i = 1; i <= n; ++i)
				if (vis[i]){
					for (int s = u, t = i; vis[t]; s = a[s], t = a[t]){
						printf("%d %d\n", s, t);
						vis[t] = false;
					}
				}
		}
		else
			puts("NO");
	}
	return 0;
}