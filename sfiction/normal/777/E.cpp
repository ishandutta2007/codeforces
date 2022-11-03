#include <bits/stdc++.h>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

int main(){
	int n;
	scanf("%d", &n);
	vector<pair<PII, int>> a(n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d%d", &a[i].st.nd, &a[i].st.st, &a[i].nd);
	sort(a.begin(), a.end());
	vector<pair<int, ll>> b;
	b.emplace_back(0, 0);
	for (int i = 0; i < n; ++i){
		auto p = lower_bound(b.begin(), b.end(), make_pair(a[i].st.nd + 1, 0ll));
		ll t = a[i].nd + (p == b.end() ? 0 : p->nd);
		for (; b.size() && b.back().nd <= t; b.pop_back());
		b.emplace_back(a[i].st.st, t);
	}
	printf("%lld\n", b[0].nd);
	return 0;
}