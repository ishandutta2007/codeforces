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

const int MAXN = 100010;
const int INF = 1e9;

int m, k;
int a[MAXN];

int t[MAXN];
int r[MAXN];

int cnt[MAXN];
int last[MAXN];

bool ans[MAXN];

int main() {
#ifdef LOCAL 
	freopen("input.txt", "r", stdin);
#endif

	int T;
	scanf("%d", &T);

	forn(testNum, T) {
		scanf("%d%d", &m, &k);

		cnt[0] = 0;
		forab(i, 1, k + 1) {
			scanf("%d", &a[i]);
			ans[i] = false;
			cnt[i] = 0;
			last[i] = 0;
		}

		
		forn(i, m - 1) {
			scanf("%d%d", &t[i], &r[i]);
			last[t[i]] = i;			
		}

		bool flag = false;

		forn(i, m - 1) {
			if (!flag && r[i]) {
				flag = true;

				int mn = INF;
				forab(j, 1, k + 1)
					if (last[j] < i && cnt[j] + cnt[0] >= a[j]) {
						ans[j] = true;
						mn = min(mn, max(0, a[j] - cnt[j]));
					}

				cnt[0] -= mn;
			}
			cnt[t[i]]++;
		}

		forab(i, 1, k + 1) {
			if (!ans[i] && cnt[i] + cnt[0] >= a[i])
				ans[i] = true;
		}

		forab(i, 1, k + 1)
			printf("%c", (ans[i] ? 'Y' : 'N'));
		printf("\n");

	}


	return 0;
}