#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1100;

int dp[MAXN][MAXN];
int choices[MAXN][MAXN];

int ar[MAXN];

int N;

int get(int front, int cur) {
	int &ret = dp[front][cur];
	int &choice = choices[front][cur];
	if (ret) return ret - 1;
	if (cur == N + 1) {
		ret = ar[front];
	} else if (cur == N) {
		ret = max(ar[front], ar[cur]);
	} else {
		int choice1 = max(ar[cur], ar[cur + 1]) + get(front, cur + 2);
		int choice2 = max(ar[front], ar[cur]) + get(cur + 1, cur + 2);
		int choice3 = max(ar[front], ar[cur + 1]) + get(cur, cur + 2);
		if (choice1 <= choice2 && choice1 <= choice3) {
			ret = choice1;
			choice = 1;
		} else if (choice2 <= choice3) {
			ret = choice2;
			choice = 2;
		} else {
			ret = choice3;
			choice = 3;
		}
	}
	return ret++;
}

void print(int front, int cur) {
	if (cur == N + 1) {
		printf("%d\n", front);
	} else if (cur == N) {
		printf("%d %d\n", front, cur);
	} else {
		int choice = choices[front][cur];
		if (choice == 1) {
			printf("%d %d\n", cur, cur + 1);
			print(front, cur + 2);
		} else if (choice == 2) {
			printf("%d %d\n", front, cur);
			print(cur + 1, cur + 2);
		} else {
			printf("%d %d\n", front, cur + 1);
			print(cur, cur + 2);
		}
	}
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i) {
		scanf("%d", ar + i);
	}

	int ans = get(1, 2);

	printf("%d\n", ans);
	print(1, 2);

	return 0;
}