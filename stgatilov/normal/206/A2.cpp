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

const int SIZE = 5<<10;

int n;
int cnt[SIZE];
vector<int> arr[SIZE];
int curr[SIZE];
vector<pair<int, int> > sol;


int main() {
#ifdef _CRT_SECURE_NO_DEPRECATE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%d", &cnt[i]);
		int a, x, y, m;
		scanf("%d%d%d%d", &a, &x, &y, &m);

		arr[i].resize(cnt[i]);
		arr[i][0] = a;
		for (int j = 1; j<cnt[i]; j++)
			arr[i][j] = (int64(arr[i][j-1]) * x + y) % m;
	}

	int last = -1;
	int ans = -1;
	while (1) {
		int best = -1;		
		for (int i = 0; i<n; i++) if (curr[i] < cnt[i])
			if (arr[i][curr[i]] >= last)
				if (best < 0 || arr[i][curr[i]] < arr[best][curr[best]])
					best = i;

		if (best < 0) {
			ans++;
			for (int i = 0; i<n; i++) if (curr[i] < cnt[i])
				if (best < 0 || arr[i][curr[i]] < arr[best][curr[best]])
					best = i;
		}
		if (best < 0) break;

		last = arr[best][curr[best]];
		curr[best]++;
		sol.push_back(make_pair(last, best+1));
	}

	printf("%d\n", ans);
	if (sol.size() <= 200000) {
		for (int i = 0; i<sol.size(); i++) printf("%d %d\n", sol[i].first, sol[i].second);
	}

	return 0;
}