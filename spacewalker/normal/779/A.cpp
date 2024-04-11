#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

vector<int> now;
vector<int> later;


int main() {
	int n; scanf("%d", &n);

	vector<int> a(5, 0);
	vector<int> b(5, 0);

	int temp;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &temp);
		++a[temp-1];
	}

	for (int i = 0; i < n; ++i) {
		scanf("%d", &temp);
		++b[temp-1];
	}

	int d = 0;
	bool success = true;
	for (int i = 0; i < 5; ++i) {
		if ((a[i] + b[i]) % 2 != 0) {
			success = false;
			break;
		} else {
			d += max(a[i] - b[i], 0)/2;
		}
	}

	printf("%d", (success? d : -1));

	return 0;
}