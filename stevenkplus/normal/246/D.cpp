#include <cstdio>
#include <set>

using namespace std;

#define sz(x) int((x).size())

const int MAXN = 100100;
set<int> cols[MAXN];
bool vis[MAXN];

int ar[MAXN];

int N, M;
int main() {
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i) {
		scanf("%d", ar + i);
		vis[ar[i]] = true;
	}
	for(int i = 0; i < M; ++i) {
		int a, b;	
		scanf("%d %d", &a, &b);
		a--;
		b--;
		a = ar[a];
		b = ar[b];
		if (a != b) {
			cols[a].insert(b);
			cols[b].insert(a);
		}
	}
	int maxc = -1;
	int ans = 0;
	for(int i = 0; i < MAXN; ++i) {
		if (vis[i] && sz(cols[i]) > maxc) {
			maxc = sz(cols[i]);
			ans = i;
		}
	}
	printf("%d\n", ans);
	return 0;
}