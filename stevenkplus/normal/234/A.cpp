#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 110;

char guys[MAXN];
int f[MAXN];
int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	int N;
	scanf("%d", &N);
	scanf("%s", guys);
	int j = 0;
	for(int i = 0; i < N; i += 2) {
		f[j++] = i;
	}
	for(int i = 1; i < N; i += 2) {
		f[j++] = i;
	}
	for(int i = 0; i + 1 < N; i += 2) {	
		int a = f[i];
		int b = f[i + 1];
		if (guys[a] == 'R' && guys[b] == 'L') {
			swap (a, b);
		}
		printf("%d %d\n", a + 1, b + 1);
	}
	return 0;
}