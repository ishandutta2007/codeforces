#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define LOWBIT(x) ((x) & -(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define SWAP(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define lol long long

#define MAXN 200005

string s;
int n, a, f[3][MAXN];

int main() {
	cin >> s;
	n = s.size();
	memset(f, 128, sizeof(f));
	f[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		a = (s[i - 1] ^ 48) % 3;
		f[a][i] = MAX(f[0][i - 1] + 1, MAX(f[1][i - 1], f[2][i - 1]));
		for (int j = 0; j <= 2; j++) {
			f[(a + j) % 3][i] = MAX(f[(a + j) % 3][i], f[j][i - 1]);
		}
	}
	printf("%d\n", MAX(f[0][n] + 1, MAX(f[1][n], f[2][n])) - 1);
	return 0;
}

// By Sooke.
//