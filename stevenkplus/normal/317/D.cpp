#include <cstdio>
#include <set>

using namespace std;

typedef long long ll;
const int LIM = 100000;

int ar[] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};

int N;

set<int> vis1;
set<int> vis2;

int main() {
	scanf("%d", &N);
	int sum = 1;
	for(int i = 2; i < LIM; ++i) {
		if (vis1.find(i) != vis1.end()) continue;
		int cnt = 0;
		for(ll j = i; j <= N; j *= i) {
			if (j < LIM) {
				vis1.insert(int(j));
			} else {
				vis2.insert(int(j));
			}
			++cnt;
		}
		sum ^= ar[cnt];
	}

	int abov = N - LIM + 1;
	abov -= int(vis2.size());
	if (abov % 2 == 1) {
		sum ^= 1;
	}

	if (sum == 0) {
		printf("Petya\n");
	} else {
		printf("Vasya\n");
	}
	return 0;
}