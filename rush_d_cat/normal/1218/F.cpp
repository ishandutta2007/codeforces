#include <iostream>
#include <set>
using namespace std;
const int N = 100000 + 10;
int n, k;
int a, x[N], c[N];
set< pair<int,int> > st;
int main() {
	// freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &x[i]);
	}
	scanf("%d", &a);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &c[i]);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i ++) {
		st.insert(make_pair(c[i], i));
		if (k >= x[i]) continue;
		int need = (x[i] - k + a - 1) / a;
		if (need > st.size()) return !printf("-1\n");
		for (int j = 0; j < need; j ++) {
			k += a, ans += (*st.begin()).first;
			st.erase(st.begin());
		}
	}
	printf("%lld\n", ans);
}