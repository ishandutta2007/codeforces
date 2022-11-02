#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 3e5 + 30;
 
int n, m;
int a[N], c[N];
set<int> A;
 
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		A.clear();
		for(int i = 1; i <= m; i++)
			scanf("%d", &c[i]), A.insert(i);
		long long ans = 0;
		for(int i = n; i; i--) {
			if(A.size() == 0) {
				ans += c[a[i]];
				continue;
			}
			int now = *A.begin();
			if(now <= a[i])ans += c[now], A.erase(now);
			else ans += c[a[i]];
		}
		printf("%lld\n", ans);
	}
}