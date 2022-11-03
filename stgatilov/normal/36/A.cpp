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

int n;
char arr[128];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	scanf("%s", arr);
	bool ans = true;
	int last = -1;
	int per = -1;
	for (int i = 0; i<n; i++)
		if (arr[i] == '1') {
			if (last >= 0) {
				if (per >= 0) {
					if (per != i - last) ans = false;
				}
				per = i - last;
			}
			last = i;
		}
	printf("%s\n", ans ? "YES" : "NO");
	return 0;
}