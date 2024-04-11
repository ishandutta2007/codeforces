#include <cstdio>
#include <algorithm>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;
typedef pair<int, PII> PIP;

const int MAXN = 1E5 + 10, MAXF = 1E4 + 10;

int n, K;
PIP a[MAXN];
vector<int> b[MAXF], c[MAXF];
int id[MAXN];
int cnt[MAXF];

inline void update(vector<int> &a, int i, int c){
	for (; i < a.size(); i = i | i + 1)
		a[i] += c;
}

inline int query(vector<int> &a, int i){
	int ret = 0;
	for (; i >= 0; i = (i & i + 1) - 1)
		ret += a[i];
	return ret;
}

inline int append(int f, int x){
	b[f].push_back(x);
	int sum = 1;
	int t = c[f].size();
	for (int j = 0; t >> j & 1; ++j)
		sum += c[f][t ^ 1 << j];
	c[f].push_back(sum);
}

int main(){
	scanf("%d%d", &n, &K);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d%d", &a[i].st, &a[i].nd.st, &a[i].nd.nd);
	sort(a + 1, a + n + 1);
	priority_queue<PII, vector<PII>, greater<PII> > Q;
	long long ans = 0;
	for (int i = 1; i <= n; ++i){
		for (; !Q.empty() && Q.top().st < a[i].st; Q.pop()){
			int t = Q.top().nd;
			--cnt[a[t].nd.nd];
			update(c[a[t].nd.nd], id[t], -1);
		}

		int f = a[i].nd.nd;
		int tl = max(1, f - K), tr = min(MAXF - 1, f + K);
		int limit = a[i].st - a[i].nd.st;
		for (int j = tl; j <= tr; ++j){
			int t = lower_bound(b[j].begin(), b[j].end(), limit) - b[j].begin();
			ans += cnt[j] - query(c[j], t - 1);
		}
		++cnt[f];
		id[i] = b[f].size();
		append(f, a[i].st);
		Q.push(PII(a[i].st + a[i].nd.st, i));
	}
	printf("%lld\n", ans);
	return 0;
}