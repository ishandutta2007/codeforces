#include <cstdio>
#include <cmath>
#include <set>
#define MAX 50000
using namespace std;

int main() {
	int a, b, c, d;
	scanf("%d %d", &a, &b);
	scanf("%d %d", &c, &d);
	set<int> rickCalls;
	set<int> mortyCalls;
	for (int s = 0; s < MAX + 1; ++s) {
		int rickTime = b + s * a;
		int mortyTime = d + s * c;
		if (mortyTime < rickTime) {
			// prioritize looking at mortyTime
			if (rickCalls.find(mortyTime) != rickCalls.end()){
				printf("%d", mortyTime);
				return 0;
			} else if (mortyCalls.find(rickTime) != mortyCalls.end()) {
				printf("%d", rickTime);
				return 0;
			}
		} else if (rickTime < mortyTime) {
			if (mortyCalls.find(rickTime) != mortyCalls.end()) {
				printf("%d", rickTime);
				return 0;
			} else if (rickCalls.find(mortyTime) != rickCalls.end()) {
				printf("%d", mortyTime);
				return 0;
			}
		} else {
			printf("%d", rickTime);
			return 0;
		}
		rickCalls.insert(rickTime);
		mortyCalls.insert(mortyTime);
	}
	printf("-1");
	return 0;
}