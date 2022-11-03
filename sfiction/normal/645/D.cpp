#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 1E5 + 10;

int n, m;
int a[MAXN], b[MAXN];

vector<int> E[MAXN];
int deg[MAXN];

bool solve(int m){
	for (int i = 1; i <= n; ++i)
		E[i].clear(), deg[i] = 0;
	for (int i = 0; i < m; ++i)
		E[b[i]].push_back(a[i]), ++deg[a[i]];
	queue<int> Q;
	for (int i = 1; i <= n; ++i)
		if (!deg[i])
			Q.push(i);
	while (!Q.empty()){
		if (Q.size() > 1)
			return false;
		int u = Q.front();
		Q.pop();
		for (int i = 0; i < E[u].size(); ++i)
			if (--deg[E[u][i]] == 0)
				Q.push(E[u][i]);
	}
	return true;
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
		scanf("%d%d", &a[i], &b[i]);
	int high = m + 1, low = n - 1, mid;
	while (low < high){
		mid = high + low >> 1;
		if (solve(mid))
			high = mid;
		else
			low = mid + 1;
	}
	printf("%d\n", low > m ? -1 : low);
	return 0;
}