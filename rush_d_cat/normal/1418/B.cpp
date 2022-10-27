#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t, n, a[N], l[N];
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i ++) scanf("%d", &l[i]);
		vector<int> v;
		for (int i = 1; i <= n; i ++) 
			if (l[i] == 0) v.push_back(a[i]);
		sort(v.begin(), v.end());
		for (int i = 1; i <= n; i ++)
			if (l[i] == 0) {
				a[i] = v.back(); v.pop_back();
			}
		for (int i = 1; i <= n; i ++)
			printf("%d ", a[i]);
		printf("\n");
	}
}