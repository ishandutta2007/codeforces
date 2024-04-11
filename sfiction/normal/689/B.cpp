#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 2E5 + 10;

int n;
int a[MAXN], dis[MAXN];

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		dis[i] = -1;
	}
	dis[1] = 0;

	queue<int> Q;
	Q.push(1);
	while (!Q.empty()){
		int u = Q.front();
		Q.pop();
		if (u != n && dis[u + 1] == -1){
			dis[u + 1] = dis[u] + 1;
			Q.push(u + 1);
		}
		if (u != 1 && dis[u - 1] == -1){
			dis[u - 1] = dis[u] + 1;
			Q.push(u - 1);
		}
		if (dis[a[u]] == -1){
			dis[a[u]] = dis[u] + 1;
			Q.push(a[u]);
		}
	}
	for (int i = 1; i <= n; ++i)
		printf("%d%c", dis[i], "\n "[i < n]);
	return 0;
}