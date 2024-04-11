#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
int n;
int b[N], ans[N];

pair<int, int> a[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &b[i]);
	}
	b[n+1] = b[1];
	for (int i = 1; i <= n; i ++) {
		a[i] = make_pair(b[i] + b[i + 1], i - 1);
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i ++) ans[a[i].second] = i - 1;
	for (int i = 0; i < n; i ++) printf("%d ", ans[i]);
}

/*
x * (n - b[1]) + (n - x) * b[2]
x * (n - b[2]) + (n - x) * b[3]


- x * b[1]- x * b[2]


b[1] = 0, b[2] = 1, b[3] = 2



x * 0 + (3 - x) * 1
x * -1 + (3 - x) * 2
x * -2 + (3 - x) * 0


-x
-3x
-2x


(0+1) * 2   0 
(1+2) * 0   2
(2+0) * 1   1



*/