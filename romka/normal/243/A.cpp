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

bool used[2200010];

int main() {
	set<int> cur;
	int n, x, ans = 0;
	scanf("%d", &n);
	forn(i, n) {
		scanf("%d", &x);
		set<int> ncur;
		foreach(it, cur)
			ncur.insert(x | (*it));
		ncur.insert(x);
		cur = ncur;
		foreach(it, ncur)
			if (!used[*it]) {
				used[*it] = 1;
				ans++;
			}
	}
	printf("%d\n", ans);
    return 0;
}