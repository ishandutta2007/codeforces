#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int gr[] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12, 14};

// map<int, int> mm;
bool u[32000];

// int grundy(int x, int n) {
// 	if (mm.find(x) != mm.end()) return mm[x];
// 	int& res = mm[x];
// 	set<int> ss;
// 	forn(j, n)
// 		if (x & (1 << j)) {
// 			int nx = x;
// 			for (int q = j; q < n; q += j + 1)
// 				if (nx & (1 << q)) nx ^= 1 << q;
// 			ss.insert(grundy(nx, n));
// 		}
// 	forn(j, 35)
// 		if (ss.find(j) == ss.end())
// 			return res = j;
// }

int solve(int n) {
	memset(u, 0, sizeof(u));
	int ans = 1;
	int sq = max(int(sqrt(1.0 * n)) - 1, 0);
	while ((sq + 1) * (sq + 1) <= n) sq++;
	int rest = n - sq;

	for (int i = 2; i <= sq; i++) {
		if (u[i]) continue;
		ll j = i;
		int cnt = 1;
		while (j * i <= n) {
			j *= i;
			cnt++;
			if (j > sq) rest--;
			else u[j] = true;
		}
		// int x = grundy((1LL << cnt) - 1, cnt);
		// if (i < 7) printf("%d: %d\n", i, x);
		// ans ^= x;
		ans ^= gr[cnt];
	}	
	if (rest & 1) ans ^= 1;
	return ans != 0;
}

int main() {
	int n;
	scanf("%d", &n);

	// for (int cnt = 1; cnt <= 30; cnt++)
	// 	printf("%d: %d\n", cnt, grundy((1LL << cnt) - 1, cnt));

	// for (int n = 1; n <= 1000; n++) {
	// 	if (!solve(n)) printf("%d\n", n);
	// }

	if (solve(n)) printf("Vasya\n");
	else printf("Petya\n");
	return 0;
}