#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MAXN = 5E2 + 10;

int n;
int a[MAXN];
vector<int> lst;

void check(int n){
	int k = 1;
	for (; k <= n / k; ++k)
		lst.emplace_back(k);
	for (int g = 1; ; ++g){
		int l = n / (g + 1) + 1, r = n / g;
		if (r < k)
			break;

		int m = (n + g - 1) / g - 1;
		m = max(m, k);
		lst.emplace_back(m);
		if (m < r)
			lst.emplace_back(r);
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	check(a[0]);
	sort(lst.begin(), lst.end(), greater<int>());
	int K = 1;
	for (int i = 0; i < lst.size(); ++i){
		bool flag = true;
		for (int j = 0; j < n; ++j)
			flag &= a[j] % lst[i] <= a[j] / lst[i];
		if (flag){
			K = lst[i];
			break;
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i)
		ans += (a[i] - 1) / (K + 1) + 1;
	printf("%lld\n", ans);
	return 0;
}