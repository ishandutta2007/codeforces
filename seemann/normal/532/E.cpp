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

using namespace std;

#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
	
typedef long long ll;
typedef long double ldb;

const int MAXN = 100010;

int n;
char s[2][MAXN];

int main() {
#ifdef LOCAL 
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d %s %s ", &n, s[0], s[1]);

	int ans = 0;

	forn(i, n)
		if (s[0][i] != s[1][i]) {
			forn(q, 2) {
				int good = 2;

				forab(j, i, n) {
					if (good == 1 && s[0][j] != s[1][j]) {
						good = 0;
						break;
					}
					if (good == 2 && j + 1 < n && s[q][j] != s[1 - q][j + 1])
						good = 1;
				}

				if (good > 0)
					ans++;
			}

			break;
		}

	cout << ans << '\n';

	return 0;
}