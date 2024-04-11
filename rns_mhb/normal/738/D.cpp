#include <bits/stdc++.h>
using namespace std;

#define N 200010

int n, a, b, k, num, sz;
char p[N];
vector <int> V;

int main() {
    scanf("%d%d%d%d", &n, &a, &b, &k);
    scanf("%s", p + 1);
	for (int i = 1; i <= n; i ++) {
		if (p[i] == '1') {
			num += sz / b;
			for (int j = i - b; j >= i - sz; j -= b) V.push_back(j);
			sz = 0;
		}
		else {
			sz ++;
			if (i == n) {
				num += sz / b;
				for (int j = n - b + 1; j >= n - sz + 1; j -= b) V.push_back(j);
				sz = 0;
			}
		}
	}
	printf("%d\n", num - a + 1);
	for (int i = 0; i < num - a + 1; i ++) printf("%d ", V[i]);
}