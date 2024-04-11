#include <climits>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1E3 + 10, MAXM = 1E4 + 10;

int n, m;
int e[MAXM][2], val[MAXM];
vector<PII> E[MAXN];
vector<int> lst;

ll SPFA(int S, int end){
	static ll dis[MAXN];
	static bool in[MAXN];

	fill_n(dis, n, 1ll << 60);
	fill_n(in, n, false);

	queue<int> Q;
	dis[S] = 0;
	in[S] = true;
	Q.push(S);
	while (!Q.empty()){
		int u = Q.front();
		Q.pop();
		for (int v, i = 0; i < E[u].size(); ++i)
			if (dis[v = E[u][i].st] > dis[u] + val[E[u][i].nd]){
				dis[v] = dis[u] + val[E[u][i].nd];
				if (!in[v]){
					in[v] = true;
					Q.push(v);
				}
			}
		in[u] = false;
	}
	return dis[end];
}

int main(){
	int L, S, E;
	scanf("%d%d%d%d%d", &n, &m, &L, &S, &E);
	for (int u, v, i = 0; i < m; ++i){
		scanf("%d%d%d", &u, &v, &val[i]);
		e[i][0] = u, e[i][1] = v;
		::E[u].push_back(PII(v, i));
		::E[v].push_back(PII(u, i));
		if (val[i] == 0)
			lst.push_back(i);
	}

	for (int i: lst)
		val[i] = INT_MAX;
	ll ret = SPFA(S, E);
	if (ret < L){
		puts("NO");
		return 0;
	}
	if (ret == L){
		puts("YES");
		for (int i = 0; i < m; ++i)
			printf("%d %d %d\n", e[i][0], e[i][1], val[i]);
		return 0;
	}
	for (int i: lst)
		val[i] = 1;
	if (SPFA(S, E) > L){
		puts("NO");
		return 0;
	}

	int low = 0, high = lst.size(), mid;
	while (low < high){
		mid = low + high >> 1;
		for (int i: lst)
			val[i] = i < lst[mid] ? 1 : INT_MAX;
		if (SPFA(S, E) < L)
			high = mid;
		else
			low = mid + 1;
	}
	int loc = max(0, low - 1);
	for (int i: lst)
		val[i] = i < lst[loc] ? 1 : INT_MAX;

	low = 1, high = INT_MAX - 1;
	while (low < high){
		mid = low + high >> 1;
		val[lst[loc]] = mid;
		if (SPFA(S, E) < L)
			low = mid + 1;
		else
			high = mid;
	}
	val[lst[loc]] = low;

	puts("YES");
	for (int i = 0; i < m; ++i)
		printf("%d %d %d\n", e[i][0], e[i][1], val[i]);
	return 0;
}