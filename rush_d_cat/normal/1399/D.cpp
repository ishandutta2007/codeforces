#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t, n, ans[N];
char s[N];

int main() {
	scanf("%d", &t);
	while (t --) {	
		scanf("%d%s", &n, s + 1);

		set<int> s0, s1;
		for (int i = 1; i <= n; i ++)
			if (s[i] == '0') s0.insert(i); else s1.insert(i);
		s0.insert(1e9); s1.insert(1e9);

		int cnt = 0;
		while (1) {
			if (s0.size() == 1 && s1.size() == 1) break;

			++ cnt;
			int h0 = *s0.begin();
			int h1 = *s1.begin();
			int flag = 0;
			if (h0 > h1) {
				flag = 1;
			}
			int las = -1;
			while(1) {
				int now;
				if (flag == 0) {
					now = *s0.lower_bound(las);
					if (now != 1e9) s0.erase(now);
				} else {
					now = *s1.lower_bound(las);
					if (now != 1e9) s1.erase(now);
				}

				if (now == 1e9) break;
				ans[now] = cnt;
				las = now;


				flag ^= 1;	
			}
		}

		printf("%d\n", cnt);
		for (int i = 1; i <= n; i ++)
			printf("%d ", ans[i]);
		printf("\n");
	}
}