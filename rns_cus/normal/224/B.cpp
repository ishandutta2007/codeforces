#include <bits/stdc++.h>
using namespace std;
#define N 100100

int n, k, a[N], gas[N];
set <int> s;

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]), s.insert(a[i]), gas[a[i]] ++;
		if (s.size() == k) {
			int st = 0, en = i;
            for (int j = 1; j <= i; j ++) {
				if (gas[a[j]] == 1) {st = j; break;}
				else gas[a[j]] --;
            }
			printf("%d %d\n", st, en);
			return 0;
		}
	}
	puts("-1 -1");
	return 0;
}