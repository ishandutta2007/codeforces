/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 555B
 */
#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;

const int MAXN = 2E5 + 100;

int n, m;
ll l[MAXN], r[MAXN];
vector<pair<ll, int> > len;
vector<pair<Pll, int> > a;

int ans[MAXN];

void init(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%I64d%I64d", &l[i], &r[i]);
	len.clear();
	for (int i = 0; i < m; ++i){
		ll t;
		scanf("%I64d", &t);
		len.push_back(make_pair(t, i + 1));
	}
	sort(len.begin(), len.end());
	
	a.clear();
	for (int i = 0; i < n - 1; ++i)
		a.push_back(make_pair(make_pair(l[i + 1] - r[i], r[i + 1] - l[i]), i));
	sort(a.begin(), a.end());
}

int main(){
	init();

	priority_queue<pair<ll, int> > Q;
	int cnt = 0;
	for (int j = 0, i = 0; i < m; ++i){
		for (; j < a.size() && len[i].first >= a[j].first.first; ++j)
			Q.push(make_pair(-a[j].first.second, a[j].second));

		while (!Q.empty() && -Q.top().first < len[i].first)
			Q.pop();
		if (!Q.empty()){
			ans[Q.top().second] = len[i].second;
			Q.pop();
			++cnt;
		}
	}
	if (cnt == n - 1){
		puts("Yes");
		printf("%d", ans[0]);
		for (int i = 1; i < n - 1; ++i)
			printf(" %d", ans[i]);
	}
	else
		puts("No");

	return 0;
}