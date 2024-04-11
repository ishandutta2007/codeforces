#include <bits/stdc++.h>

using namespace std;

char seqn[1000010];

int main() {
	int n; scanf("%d", &n);	
	scanf("%s", seqn);
	int bal = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		bal += (seqn[i] == '(' ? 1 : -1);
		if (bal < 0 || (bal == 0 && seqn[i] == '(')) ++ans;
	}
	if (bal != 0) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}