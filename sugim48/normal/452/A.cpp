#include <algorithm>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int main() {
	int n; scanf("%d", &n);
	char s[9]; scanf("%s", s);
	char t[8][9] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
	int i;
	for (i = 0; i < 8; i++) {
		bool flag = (strlen(t[i]) == n);
		for (int j = 0; j < n; j++)
			if (s[j] != '.' && s[j] != t[i][j])
				flag = false;
		if (flag)
			break;
	}
	printf("%s\n", t[i]);
}