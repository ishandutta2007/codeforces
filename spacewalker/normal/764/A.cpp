#include <iostream>

using namespace std;

int main() {
	int n, m, z;
	scanf("%i %i %i", &n, &m, &z);

	int artistsKilled = 0;

	for (int day = 1; day <= z; ++day) {
		if (day % m == 0 && day % n == 0) {
			++artistsKilled;
		}
	}

	printf("%i", artistsKilled);
	return 0;
}