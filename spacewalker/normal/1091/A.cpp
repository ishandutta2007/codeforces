#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <utility>
#include <cmath>

using namespace std;
typedef long long ll;

int main() {
	int y, b, r; scanf("%d %d %d", &y, &b, &r);
	int x = min(y, min(b-1, r-2));
	printf("%d\n", 3*x + 3);
	return 0;
}