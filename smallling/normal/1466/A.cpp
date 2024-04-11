#include <bits/stdc++.h>

using namespace std;

int n, a[110];
set<int> A;

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		A.clear();
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n; j++)
				A.insert(a[j] - a[i]);
		printf("%d\n", A.size());
	}
}