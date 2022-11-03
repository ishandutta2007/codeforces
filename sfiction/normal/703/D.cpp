#include <cstdio>
#include <map>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 1E6 + 10;

int n, m;
int a[MAXN], pre[MAXN];
vector<PII> b[MAXN];
int ans[MAXN];

int sum[MAXN];

void update(int i, int c){
	for (; i <= n; i = (i | i - 1) + 1)
		sum[i] ^= c;
}

int query(int i){
	int ret = 0;
	for (; i > 0; i &= i - 1)
		ret ^= sum[i];
	return ret;
}

int query(int l, int r){
	return query(r) ^ query(l - 1);
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		pre[i] = pre[i - 1] ^ a[i];
	}
	scanf("%d", &m);
	for (int l, r, i = 0; i < m; ++i){
		scanf("%d%d", &l, &r);
		b[r].push_back(PII(l, i));
		ans[i] = pre[r] ^ pre[l - 1];
	}

	map<int, int> lst;
	for (int i = 1; i <= n; ++i){
		if (lst.find(a[i]) != lst.end())
			update(lst[a[i]], a[i]);
		lst[a[i]] = i;
		update(i, a[i]);

		for (int j = 0; j < b[i].size(); ++j)
			ans[b[i][j].nd] ^= query(b[i][j].st, i);
	}
	for (int i = 0; i < m; ++i)
		printf("%d\n", ans[i]);
	return 0;
}