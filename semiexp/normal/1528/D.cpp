#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, M;
vector<pair<int, int>> D[660];
int ans[660][660];

int md[660];
bool visited[660];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i) {
		int s, t, c;
		scanf("%d%d%d", &s, &t, &c);
		D[s].push_back({c, t});
	}
	for (int i = 0; i < N; ++i) sort(D[i].begin(), D[i].end());

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			md[j] = 1100000000;
			visited[j] = false;
		}
		for (auto& p : D[i]) {
			md[p.second] = min(md[p.second], p.first);
		}

		for (int j = 0; j < N; ++j) {
			int bp = -1;
			for (int k = 0; k < N; ++k) {
				if (!visited[k] && (bp == -1 || md[bp] > md[k])) {
					bp = k;
				}
			}
			visited[bp] = true;
			for (auto& p : D[bp]) {
				int dest = p.second;
				int cost = p.first;
				dest = (dest + md[bp]) % N;
				md[dest] = min(md[dest], md[bp] + cost);
			}

			int a = j, b = (j + 1) % N;
			for (int k = 0; k < N; ++k) {
				md[b] = min(md[b], md[a] + 1);
				a = b;
				b = b + 1;
				if (b == N) b = 0;
			}
		}
		for (int j = 0; j < N; ++j) ans[i][j] = md[j];
		ans[i][i] = 0;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) printf("%d%c", ans[i][j], j == N - 1 ? '\n' : ' ');
	}
	return 0;
}