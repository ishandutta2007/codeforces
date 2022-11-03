#include <bits/stdc++.h>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<ll> a[4];
char s[50];

int main(){
	char s[4];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		int x;
		scanf("%s%d", s, &x);
		int t = (s[0] - '0') * 2 + (s[1] - '0');
		a[t].push_back(x);
	}

	for (int i = 0; i < 4; ++i)
		sort(a[i].begin(), a[i].end(), greater<int>());

	ll ans = 0;
	for (auto &x: a[3])
		ans += x;
	if (a[1].size() < a[2].size())
		a[1].swap(a[2]);
	for (int i = 0; i < a[2].size(); ++i)
		ans += a[1][i] + a[2][i];
	for (int i = 0; i < a[3].size() && i < a[0].size(); ++i)
		ans += a[0][i];

	ll sum = ans;
	int t = a[3].size() - 1;
	for (int i = a[2].size(); i < a[1].size() && i < a[2].size() + a[3].size(); ++i){
		sum += a[1][i];
		if (t < a[0].size())
			sum -= a[0][t];
		--t;
		ans = max(ans, sum);
	}
	printf("%lld\n", ans);
	return 0;
}