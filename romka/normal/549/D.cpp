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

int n, m;
char s[110][110];
ll a[110][110], sr[110][110], sd[110][110], sp[110][110];

int main() {
	scanf("%d %d", &n, &m);
	forn(i, n) scanf("%s", s[i]);
	int ans = 0;
	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--) {
			int need = (s[i][j] == 'B' ? -1 : 1);
			sp[i][j] = sr[i][j+1] + sd[i+1][j] + sp[i+1][j+1];
			sr[i][j] = sr[i][j+1];
			sd[i][j] = sd[i+1][j];
			a[i][j] = sp[i][j];
			if (a[i][j] != need) {
				ans++;
				ll c = need - a[i][j];
				sr[i][j] += c;
				sd[i][j] += c;
				sp[i][j] += c;
				a[i][j] = need;
			}
		}

	printf("%d\n", ans);

	return 0;
}