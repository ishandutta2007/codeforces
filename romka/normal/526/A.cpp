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
char s[110];

int main() {
	scanf("%d", &n);
	scanf("%s", s);
	forn(i, n) if (s[i] == '*')
		for (int d = 1; i + 4 * d < n; d++) {
			bool ok = true;
			forn(q, 5) ok &= s[i + d*q] == '*';
			if (ok) {
				printf("yes\n");
				return 0;
			}
		}
	printf("no\n");
	return 0;
}