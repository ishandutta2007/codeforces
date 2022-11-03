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

char str[16];
set<string> all;

void DFS(string s) {
	all.insert(s);

	char r1[] = {s[1], s[2], s[3], s[0], s[4], s[5], 0};
	if (all.find(r1) == all.end())
		DFS(r1);

	char r2[] = {s[0], s[4], s[2], s[5], s[3], s[1], 0};
	if (all.find(r2) == all.end())
		DFS(r2);
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%s", str);
	sort(str, str+6);
	int ans = 0;
	do {
		if (all.find(str) != all.end()) continue;
		ans++;
		DFS(str);
	} while (next_permutation(str, str+6));
    printf("%d\n", ans);
	return 0;
}