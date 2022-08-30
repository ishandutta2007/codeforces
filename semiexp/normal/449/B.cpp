#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;
#define MOD 1000000009
#define ADD(X, Y) ((X) = ((X) + (Y)) % MOD)

typedef long long i64;

int N, M, K;
vector<int> to[100000], dist[100000];
bool vis[100000];

int main()
{
	scanf("%d%d%d", &N, &M, &K);

	for (int i = 0; i < M; i++) {
		int u, v, x;
		scanf("%d%d%d", &u, &v, &x);

		--u; --v;

		to[u].push_back(v);
		dist[u].push_back(x);
		to[v].push_back(u);
		dist[v].push_back(x);
	}

	for (int i = 0; i < N; i++) vis[i] = false;

	priority_queue<pair<i64, int> > Q;
	Q.push(make_pair((i64)0, 0));
	
	for (int i = 0; i < K; i++) {
		int s, y;
		scanf("%d%d", &s, &y);

		--s;

		Q.push(make_pair(-(i64)y, s - N));
	}

	int ret = 0;

	while(!Q.empty()) {
		pair<i64, int> tmp = Q.top(); Q.pop();

		if (tmp.second < 0) {
			tmp.second += N;

			if(vis[tmp.second]) ++ret;
		}

		if(vis[tmp.second]) continue;
		vis[tmp.second] = true;

		int p = tmp.second;

		for(int i=0;i<to[p].size();i++) Q.push(make_pair(tmp.first - dist[p][i], to[p][i]));
	}

	printf("%d\n", ret);
	return 0;
}