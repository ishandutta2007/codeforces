#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 200000 + 10;
int t, n;
int ask(int x, int y) {
	printf("? %d %d\n", x, y); fflush(stdout);
	int ans; scanf("%d", &ans);
	return ans;
}
int ans[N];
set<int> st;
int pre = 1;
int link(int x, int y) {
	int f1 = ask(x, y);
	int f2 = ask(y, x);
	if (f1 > f2) {
		ans[x] = f1; pre = y; st.erase(f1);
	} else {
		ans[y] = f2; pre = x; st.erase(f2);
	}
}
int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i ++) {
		st.insert(i);
	}
	for (int i = 2; i <= n; i ++) {
		link(pre, i);
	}
	printf("! ");
	for (int i = 1; i <= n; i ++) {
		if (ans[i]) printf("%d ", ans[i]);
		else printf("%d ", *st.begin());
	}
	fflush(stdout);
}