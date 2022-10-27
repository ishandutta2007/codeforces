#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 52;
int t, n, m, a[N][N];
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d",&n,&m);
		set<int> R,C;
		for(int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				scanf("%d", &a[i][j]);
				if (a[i][j] == 0) {
					R.insert(i);
					C.insert(j);
				}
			}
		}
		for(int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				if (a[i][j] == 1) {
					if (R.count(i)) R.erase(i);
					if (C.count(j)) C.erase(j);
				}
			}
		}
		int len = min(R.size(), C.size());
		printf("%s\n", len % 2 == 0 ? "Vivek" : "Ashish");
	}
}