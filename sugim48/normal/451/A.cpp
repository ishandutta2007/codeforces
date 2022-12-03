#include <algorithm>
#include <cstdio>
#include <climits>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	printf(min(n, m) % 2 == 0 ? "Malvika\n" : "Akshat\n");
}