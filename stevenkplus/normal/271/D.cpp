#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>

using namespace std;

typedef unsigned long long ull;
typedef pair<ull, ull> pll;

const int MAXC = 30;
const int MAXN = 1600;
const int P1 = 1E9 + 7;
const int P2 = 1E9 + 9;

char str[MAXN];
char buf[MAXC];
bool good[MAXC];

set<pll> myset;
int N, K;

int main() {
	scanf("%s", str);
	N = strlen(str);
	scanf("%s", buf);
	for(int i = 0; i < 26; ++i) {
		good[i] = buf[i] == '1';
	}
	scanf("%d", &K);

	for(int i = 0; i < N; ++i) {
		ull hash1 = 1, hash2 = 1;
		int numbad = 0;
		for(int j = i; j <= N && numbad <= K; ++j) {
			myset.insert(pll(hash1, hash2));

			if (j == N) break;
			int cur = str[j] - 'a';
			if (!good[cur]) {
				++numbad;
			}
			hash1 = hash1 * P1 + cur;
			hash2 = hash2 * P2 + cur;
		}
	}

	int ans = int(myset.size()) - 1; // overcount - empty string.
	printf("%d\n", ans);
	return 0;
}