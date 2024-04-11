#include <cstdio>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

const int MAXN = 30;

int a[MAXN][3];

map<PII, PII> lst;

int limit;
ll ans, ansr;

void DFS1(int depth, int s0, int s1, int s2, int r){
	if (depth <= limit){
		PII t = PII(s1 - s0, s2 - s0);
		if (lst.find(t) == lst.end() || lst[t].first < s0)
			lst[t] = PII(s0, r);
		return;
	}
	DFS1(depth - 1, s0, s1 + a[depth][1], s2 + a[depth][2], r << 2);
	DFS1(depth - 1, s0 + a[depth][0], s1, s2 + a[depth][2], r << 2 | 1);
	DFS1(depth - 1, s0 + a[depth][0], s1 + a[depth][1], s2, r << 2 | 2);
}

void DFS2(int depth, int s0, int s1, int s2, int r){
	if (depth <= limit){
		pair<int, int> t = PII(s0 - s1, s0 - s2);
		if (lst.find(t) != lst.end() && ans < (ll)s0 + lst[t].first){
			ans = max(ans, (ll)s0 + lst[t].first);
			ansr = (ll)r << limit * 2 | lst[t].second;
		}
		return;
	}
	DFS2(depth - 1, s0, s1 + a[depth][1], s2 + a[depth][2], r << 2);
	DFS2(depth - 1, s0 + a[depth][0], s1, s2 + a[depth][2], r << 2 | 1);
	DFS2(depth - 1, s0 + a[depth][0], s1 + a[depth][1], s2, r << 2 | 2);
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
	limit = 0;
	DFS1(n >> 1, 0, 0, 0, 0);
	ans = -(1ll << 60);
	limit = n >> 1;
	DFS2(n, 0, 0, 0, 0);
	if (ans == -(1ll << 60))
		puts("Impossible");
	else{
		ll t = ansr;
		for (int i = 0; i < n; ++i){
			int tt = t & 3;
			t >>= 2;
			puts(tt == 0 ? "MW" : tt == 1 ? "LW" : "LM");
		}
	}
	return 0;
}