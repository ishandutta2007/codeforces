#include <cstdio>

using namespace std;

int main() {
	int x,y,a,b;
	scanf("%d %d %d %d", &x, &y, &a, &b);
	bool found = false;
	int cnt = 0;
	for(int i = a; i <= x; ++i) {
		for(int j = b; j < i && j <= y; ++j) {
			cnt++;
		}
	}
	printf("%d\n", cnt);
	for(int i = a; i <= x; ++i) {
		for(int j = b; j < i && j <= y; ++j) {
			printf("%d %d\n", i, j);
		}
	}
	return 0;
}