#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define fs first
#define sc second

pair<int, int> a[300100];
int ans[300100];

int main() {
	int n;
	scanf("%d", &n);
	forn (i, n) {
		scanf("%d", &a[i].fs);
		a[i].sc = i;
	}
	sort(a, a + n);
	int cur = 0;
	forn (i, n) {
		cur = max(cur, a[i].fs);
		ans[a[i].sc] = cur;
		++cur;
	}
	forn (i, n) {
		printf("%d ", ans[i]);
	}
}