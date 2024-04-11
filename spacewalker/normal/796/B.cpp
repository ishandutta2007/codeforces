#include <cstdio>
#include <vector>
#define BONE_START 0

using namespace std;

int main() {
	int cups, holes, swaps;
	scanf("%d %d %d", &cups, &holes, &swaps);

	vector<bool> isHole(cups, false);
	int temp;
	for (int i = 0; i < holes; ++i) {
		scanf("%d", &temp);
		isHole[--temp] = true;
	}

	int bonePos = BONE_START;
	bool isOnGround = (isHole[BONE_START]);

	for (int swap = 0; swap < swaps; ++swap) {
		int ui, vi;
		scanf("%d %d", &ui, &vi);
		--ui; --vi;
		if (isOnGround) {
			continue;
		}
		if (bonePos == ui) {
			bonePos = vi;
		} else if (bonePos == vi) {
			bonePos = ui;
		}
		if (isHole[bonePos]) {
			isOnGround = true;
		}
	}

	printf("%d", bonePos + 1);
	return 0;
}