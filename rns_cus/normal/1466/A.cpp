#include <bits/stdc++.h>
using namespace std;

#define N 55

int n, x[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &x[i]);
		set <int> S;
		for (int i = 1; i <= n; i ++) for (int j = 1; j < i; j ++) S.insert(x[i] - x[j]);
		printf("%d\n", S.size());
    }

    return 0;
}