#include <bits/stdc++.h>
using namespace std;
#define M 300100
int ABS(int u) {return u < 0 ? -u : u;}

int n;

int m;
int t[M];
map<int, int> last;


int main() {
	scanf("%d", &n);
	for (int x, i = 1; i <= n; i++) {
		scanf("%d", &x);
		if (!last.count(x)) {
			last[x] = i;
		} else {
			t[m++] = last[x];
			t[m++] = i;
			last.clear();
		}
	}
	if (m == 0) {
		puts("-1");
	} else {
		printf("%d\n", m / 2);
		t[0] = 1;
		for (int i = 2; i < m; i += 2) {
			if (t[i] > t[i-1] + 1) {
				t[i] = t[i-1] + 1;
			}
		}
		t[m - 1] = n;
		for (int i = 0; i < m; i++) {
			printf("%d ", t[i]);
		}
	}
	return 0;
}