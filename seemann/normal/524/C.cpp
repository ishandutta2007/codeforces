#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <cmath>
#include <complex>
#include <iomanip>

using namespace std;

#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
	
typedef long long ll;
typedef long double ldb;

const int MAXA = 1e7 + 10;
const int MAXN = 5010;

bool used[MAXA];

int n, k;
int a[MAXN];

int main() {
#ifdef LOCAL 
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d", &n, &k);

	memset(used, 0, sizeof(used));

	forn(i, n) {
		scanf("%d", &a[i]);
		used[a[i]] = true;
	}

	int q;
	scanf("%d", &q);
	forn(t, q) {
		int x;
		scanf("%d", &x);

		int ans = -1;

		forba(cnt, k + 1, 1) {
			if (x % cnt == 0 && x / cnt < MAXA && used[x / cnt]) {
				ans = cnt;
				continue;
			}

			forn(i, n) {
				if (ans == cnt)
					break;

				int y = x;
				int k2 = cnt;
				forab(k1, 1, cnt) {
					y -= a[i];
					k2--;

					if (y < 0)
						break;

					if (y % k2 == 0 && y / k2 < MAXA && used[y / k2]) {
						ans = cnt;
						break;
					}
				}
			}
		}

		printf("%d\n", ans);
	}


	return 0;
}