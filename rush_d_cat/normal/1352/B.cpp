#include <bits/stdc++.h>
using namespace std;
int t, n, k;
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d", &n, &k);
		vector<int> v1, v2;

		bool ok = 0;

		{
			int tmp = n;
			for (int i = 1; i < k; i ++) {
				v1.push_back(1); tmp --;
			}
			v1.push_back(tmp);
			if (tmp % 2 == 1 && tmp > 0) {
				ok = 1;
				printf("YES\n");
				for (auto x: v1) 
					printf("%d ", x);
				printf("\n");
				continue;
			}
		}

		{
			int tmp = n;
			for (int i = 1; i < k; i ++) {
				v2.push_back(2); tmp -= 2;
			}
			v2.push_back(tmp);
			if (tmp % 2 == 0 && tmp > 0) {
				ok = 1;
				printf("YES\n");
				for (auto x: v2) 
					printf("%d ", x);
				printf("\n");
				continue;
			}
		}

		printf("NO\n");

	}
}