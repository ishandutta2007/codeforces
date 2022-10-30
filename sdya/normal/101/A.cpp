#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
char s[maxN];
int k;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%s", &s);
	scanf("%d", &k);
	vector < int > cnt(26);
	int n = strlen(s);
	for (int i = 0; i < n; ++i) {
		++cnt[s[i] - 'a'];
	}
	vector < pair < int, int > > a;
	for (int i = 0; i < 26; ++i) {
		a.push_back(make_pair(cnt[i], i));
	}
	sort(a.begin(), a.end());
	vector < bool > unused(26, false);
	int total = 0;
	for (int i = 0; i < a.size(); ++i) {
		if (total + a[i].first <= k) {
			total += a[i].first;
			unused[a[i].second] = true;
		} else {
			break;
		}
	}
	printf("%d\n", count(unused.begin(), unused.end(), false));
	for (int i = 0; i < n; ++i) {
		if (!unused[s[i] - 'a']) {
			printf("%c", s[i]);
		}
	}
	printf("\n");
	
	return 0;
}