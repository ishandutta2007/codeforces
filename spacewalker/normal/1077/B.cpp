#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

int flat[200];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", flat + i);
	int toSwitch = 0;
	for (int i = 1; i < n; ++i) {
		if (flat[i-1] == 1 && flat[i] == 0 && flat[i+1] == 1) {
			++toSwitch;
			flat[i+1] = 0;
		}
	}
	printf("%d\n", toSwitch);
	return 0;
}