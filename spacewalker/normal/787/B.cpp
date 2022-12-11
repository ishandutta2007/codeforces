#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int main() {
	int n, m, temp; scanf("%d %d", &n, &m);
	bool tCanDestroy = false;
	for (int group = 0; group < m; ++group) {
		bool groupCanDestroy = true;
		set<int> members;
		int memCount; scanf("%d", &memCount);
		for (int mem = 0; mem < memCount; ++mem) {
			scanf("%d", &temp);
			if (members.find(-temp) != members.end()) {
				groupCanDestroy = false;
			}
			members.insert(temp);
		}
		tCanDestroy = (tCanDestroy || groupCanDestroy);
	}

	if (tCanDestroy) {
		printf("YES");
	} else {
		printf("NO");
	}

	return 0;
}