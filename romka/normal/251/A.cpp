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

int n, d, a[100010];

int main() {
	scanf("%d %d", &n, &d);
	forn(i, n) scanf("%d", &a[i]);
	int ip = 0;
	ll ans = 0;
	forn(i, n) {
		while (a[i] - a[ip] > d) ip++;
		if (ip < i - 1)
			ans += (i - ip) * (ll)(i - ip - 1) / 2;
	}
	cout << ans << endl;
    return 0;
}