#include <cstdio>
#include <algorithm>

using namespace std;

#define x first 
#define y second

pair <int, int> a, b;
int ans;

int main() {
	scanf("%d%d%d%d", &a.y, &a.x, &b.y, &b.x);
	while (max(a.x, b.x) < 10000) {
		if (a.x == b.x) {
			printf("%d", a.x);
			return 0;
		}
		if (a.x < b.x) a.x += a.y;
		else b.x += b.y;
	}
	puts("-1");
	return 0;
}