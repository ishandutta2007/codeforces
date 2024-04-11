#include <algorithm>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int a[100002];

int main() {
	int n; scanf("%d", &n);
	a[0] = INT_MIN; a[n + 1] = INT_MAX;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int _i = -1;
	for (int i = 1; i <= n; i++)
		if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
			if (_i == -1) _i = i;
			else { printf("no\n"); return 0; }
		}
	int _j = -1;
	for (int j = 1; j <= n; j++)
		if (a[j - 1] > a[j] && a[j] < a[j + 1]) {
			if (_j == -1) _j = j;
			else { printf("no\n"); return 0; }
		}
	if (_i == -1 && _j == -1)
		printf("yes\n1 1\n");
	else if (a[_i] < a[_j + 1] && a[_j] > a[_i - 1])
		printf("yes\n%d %d\n", _i, _j);
	else
		printf("no\n");
}