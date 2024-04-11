//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N];
int main() {
	int n;
	scanf("%d", &n);
	int cur = 0, ans = 0, last = 1e9 + 7;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] < last)
			cur = 0;
		cur++;
		last = a[i];
		ans = max(ans, cur);
	}
	cout << ans << endl;
	return 0;
}