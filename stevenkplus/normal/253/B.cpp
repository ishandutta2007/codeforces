#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
int ar[MAXN];
int N;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%d", ar + i);
	}
	sort(ar, ar + N);
	int top = 0;
	int miner = N;
	for(int i = 0; i < N; ++i) {
		while (top < N && ar[i] * 2 >= ar[top]) {
			top++;
		}
		int er = i + N - top;
		miner = min(miner, er);
	}
	printf("%d\n", miner);
	return 0;
}