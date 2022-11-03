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
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

struct Item {
	int64 cost;
	int type;
	int name;

	inline bool operator< (const Item &b) const {
		return cost > b.cost;
	}
};

const int SIZE = 1<<16;

int n, k;
Item arr[SIZE];
bool used[SIZE];

int64 ans;
vector<vector<int> > place;

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &k);
	for (int i = 0; i<n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		arr[i].cost = a;
		arr[i].type = b;
		arr[i].name = i;
	}

	sort(arr, arr+n);

	for (int i = 0; i<n; i++) if (arr[i].type == 1) {
		if (place.size() >= k-1) break;

		vector<int> t;
		t.push_back(i);
		place.push_back(t);

		used[i] = true;
	}

	for (int i = 0; i<n; i++) if (!used[i]) {
		if (place.size() >= k-1) break;

		vector<int> t;
		t.push_back(i);
		place.push_back(t);

		used[i] = true;
	}
		
	vector<int> t;
	for (int i = 0; i<n; i++) if (!used[i]) {
		t.push_back(i);
		used[i] = true;
	}
	place.push_back(t);

	assert(place.size() == k);

	int64 ans = 0;
	for (int i = 0; i<k; i++) {
		int64 tsum = 0;
		int64 tmin = 1000000000000000000LL;
		bool hast = false;
		for (int j = 0; j<place[i].size(); j++) {
			int q = place[i][j];
			tmin = min(tmin, arr[q].cost);
			tsum += arr[q].cost;
			if (arr[q].type == 1) hast = true;
		}
		ans += 2 * tsum;
		if (hast) ans -= tmin;
	}

	printf("%I64d.%d\n", ans/2, int(ans%2) * 5);
	for (int i = 0; i<k; i++) {
		printf("%d", place[i].size());
		for (int j = 0; j<place[i].size(); j++) {
			int q = place[i][j];
			printf(" %d", arr[q].name + 1);
		}
		printf("\n");
	}


	return 0;
}