#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

char s[1000010];
const int sh = 1000015;
int ans[sh + sh + 10];

int main() {
	scanf("%s", s);
	int n = strlen(s);
	ans[sh + 0] = n;
	int l = sh, r = sh;
	for (int i = n-2; i>=0; i--) {
		if (s[i] == 'l') ans[++r] = i + 1;
		else ans[--l] = i + 1;
	}
	for (int q = l; q <= r; q++) {
		printf("%d\n", ans[q]);
	}

	return 0;
}