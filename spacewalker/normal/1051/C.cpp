#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int occ[200], arr[200];
bool inA[200];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i)  {
		scanf("%d", arr + i); arr[i]--;
		occ[arr[i]]++;
	}
	vector<int> once, many;
	for (int i = 0; i < 100; ++i) {
		if (occ[i] == 1) once.push_back(i);
		else if (occ[i] >= 3) many.push_back(i);
	}
	// twice can be assigned anywhere
	// it's possible iff once + many is even
	int forceANum = -1;
	if (once.size() % 2 == 1) {
		if (many.size() == 0) {
			printf("NO\n");
			return 0;
		} else {
			forceANum = many[0];
		}
	}
	// once.insert(once.end(), many.begin(), many.end());
	for (int i = 0; i < once.size()/2; ++i) {
		// printf("all %d in A\n", once[i]);
		inA[once[i]] = true;
	}
	printf("YES\n");
	for (int i = 0; i < n; ++i) {
		if (inA[arr[i]]) printf("A");
		else if (arr[i] == forceANum) {
			printf("A");
			forceANum = -1;
		} else printf("B");
	}
	printf("\n");
	return 0;
}