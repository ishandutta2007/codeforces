#include <climits>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 4E5 + 10, MAXM = 4E5 + 10;

int n, m;
int a[MAXN];
int pre[MAXN], suf[MAXN];
int cnt[MAXN];

vector<PII> E[MAXN];

int loc[MAXM], val[MAXM];
int pre2[MAXM], suf2[MAXM];

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	
	vector<int> lst(1, INT_MIN);
	for (int i = 1; i <= n; ++i){
		pre[i] = lower_bound(lst.begin(), lst.end(), a[i]) - lst.begin();
		if (pre[i] >= lst.size())
			lst.push_back(a[i]);
		else
			lst[pre[i]] = min(lst[pre[i]], a[i]);
	}
	lst.clear();
	lst.push_back(INT_MIN);
	for (int i = n; i >= 1; --i){
		suf[i] = lower_bound(lst.begin(), lst.end(), -a[i]) - lst.begin();
		if (suf[i] >= lst.size())
			lst.push_back(-a[i]);
		else
			lst[suf[i]] = min(lst[suf[i]], -a[i]);
	}

	int len0 = 0;
	for (int i = 1; i <= n; ++i)
		len0 = max(len0, pre[i] + suf[i] - 1);
	for (int i = 1; i <= n; ++i)
		if (pre[i] + suf[i] - 1 == len0)
			++cnt[pre[i]];

	for (int  i = 0; i < m; ++i){
		scanf("%d%d", &loc[i], &val[i]);
		E[loc[i]].push_back(PII(val[i], i));
	}

	lst.clear();
	lst.push_back(INT_MIN);
	for (int i = 1; i <= n; ++i){
		for (int j = 0; j < E[i].size(); ++j)
			pre2[E[i][j].nd] = lower_bound(lst.begin(), lst.end(), E[i][j].st) - lst.begin();
		if (pre[i] >= lst.size())
			lst.push_back(a[i]);
		else
			lst[pre[i]] = min(lst[pre[i]], a[i]);
	}
	lst.clear();
	lst.push_back(INT_MIN);
	for (int i = n; i >= 1; --i){
		for (int j = 0; j < E[i].size(); ++j)
			suf2[E[i][j].nd] = lower_bound(lst.begin(), lst.end(), -E[i][j].st) - lst.begin();
		if (suf[i] >= lst.size())
			lst.push_back(-a[i]);
		else
			lst[suf[i]] = min(lst[suf[i]], -a[i]);
	}

	for (int i = 0; i < m; ++i){
		int u = loc[i];
		int len1 = len0 - (pre[u] + suf[u] - 1 == len0 && cnt[pre[u]] == 1);
		int len2 = pre2[i] + suf2[i] - 1;
		printf("%d\n", max(len1, len2));
	}
	return 0;
}