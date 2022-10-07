#include <cstdio>
#include <algorithm>

using namespace std;

const int inf = 1 << 30;
const int MAXN = 100100;

int ar[MAXN];

int N;

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	scanf("%d", &N);
	int pos = 0;
	for(int i = 0; i < N; ++i) {
		scanf("%d", ar + i);
		if (ar[i] > 0) {
			pos++;
		}
	}
	int minch = inf;	
	int neg = 0;
	for(int i = 0; i <= N; ++i) {
		int changel = i - neg;
		int changer = (N - i) - pos;
		if (i > 0 && i < N) {
			minch = min(minch, changel + changer);
		}
		if (i < N) {
			if (ar[i] < 0) {
				neg++;
			} else if (ar[i] > 0) {
				pos--;
			}
		}
	}
	printf("%d\n", minch);
	return 0;
}