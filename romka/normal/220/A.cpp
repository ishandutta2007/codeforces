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

int n, a[100010], b[100010];

int main() {
	scanf("%d", &n);
	forn(i, n) scanf("%d", &a[i]), b[i] = a[i];
	sort(a, a+n);
	int cnt = 0;
	forn(i, n) cnt += b[i] != a[i];
	if (cnt < 3) printf("YES\n");
	else printf("NO\n");
    return 0;
}