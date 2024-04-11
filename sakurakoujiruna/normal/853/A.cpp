#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back
#define fir first
#define sec second

const int N = 3e5L + 11;
int a[N], t[N];

using ll = long long;

int main() {
	int n, k; cin >> n >> k; //k = min(k, n - 1);
	for(int i = 1; i <= n; i ++)
		scanf("%d", a + i);
	multiset <pair <int, int>> st;
	for(int i = 1; i <= k; i ++)
		st.insert({a[i], i});
	
	ll ans = 0; vi v;
	for(int i = k + 1; i <= k + n; i ++) {
		if(i <= n) st.insert({a[i], i});
		auto p = *st.rbegin();
		ans += (i - p.sec) * ll(p.fir);
		t[p.sec] = i;
		st.erase(p);
	}
	cout << ans << '\n';
	for(int i = 1; i <= n; i ++)
		printf("%d ", t[i]);
	return 0;
}