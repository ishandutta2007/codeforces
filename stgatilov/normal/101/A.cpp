#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

typedef pair<int, int> pii;

int n, k;
char str[1<<20];

pii cnt[256];
bool del[256];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%s", str);
	n = strlen(str);
	scanf("%d", &k);

	for (int i = 0; i<256; i++) cnt[i].second = i;
	for (int i = 0; str[i]; i++) cnt[str[i]].first++;
	sort(cnt, cnt+256);

	for (int i = 0; i<256; i++) {
		if (cnt[i].first > k) break;
		k -= cnt[i].first;
		del[cnt[i].second] = true;
	}

	int ans = 0;
	for (int i = 0; i<256; i++) ans += !del[i];

	printf("%d\n", ans);
	for (int i = 0; i<n; i++) if (!del[str[i]]) printf("%c", str[i]);
	printf("\n");

	return 0;
}