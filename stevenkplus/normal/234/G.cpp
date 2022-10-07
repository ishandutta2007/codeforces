#include <cstdio>
#include <vector>

using namespace std;

#define sz(x) int((x).size())

int cntBits(int x) {
	int sum = 0;
	while (x > 0) {
		sum++;
		x /= 2;
	}
	return sum;
}

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	int N;
	scanf("%d", &N);
	int x = cntBits(N - 1);
	printf("%d\n", x);
	for(int i = 0; i < x; ++i) {
		vector<int> v;
		for(int x = 0; x < N; ++x) {
			if ((x >> i) & 1) {
				v.push_back(x);
			}
		}
		int size = sz(v);
		printf("%d", size);
		for(int i = 0; i < size; ++i) {
			printf(" %d", v[i]);
		}
		printf("\n");
	}
	return 0;
}