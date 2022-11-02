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

int n;
char a[110][110];

int main() {
	scanf("%d", &n);
	forn(i, n) scanf("%s", a[i]);
	{
		bool ok = true;
		forn(i, n) {
			bool flag = false;
			forn(j, n) if (a[i][j] == '.') flag = true;
			ok &= flag;
		}

		if (ok) {
			forn(i, n) {
				forn(j, n)
					if (a[i][j] == '.') {
						printf("%d %d\n", i + 1, j + 1);
						break;
					}
			}
			return 0;
		}
	}

	{
		bool ok = true;
		forn(i, n) {
			bool flag = false;
			forn(j, n) if (a[j][i] == '.') flag = true;
			ok &= flag;
		}

		if (ok) {
			forn(i, n) {
				forn(j, n)
					if (a[j][i] == '.') {
						printf("%d %d\n", j + 1, i + 1);
						break;
					}
			}
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}