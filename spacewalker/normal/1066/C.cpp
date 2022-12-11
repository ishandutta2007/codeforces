#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int pos[300000];

int main() {
	int q; scanf("%d", &q);
	int afterLeft = -1, afterRight = 0;
	for (int qta = 0; qta < q; ++qta) {
		char type; int id; scanf(" %c %d", &type, &id);
		if (type == 'R') {
			pos[id] = afterRight++;
		} else if (type == 'L') {
			pos[id] = afterLeft--;
		} else {
			printf("%d\n", min(pos[id] - afterLeft - 1, afterRight - pos[id] - 1));
		}
	}
	return 0;
}