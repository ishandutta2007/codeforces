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
typedef pair<int, int> pii;
set<pii> active;


int main() {
#ifdef _CRT_SECURE_NO_DEPRECATE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	int szsum = 0;
	for (int i = 0; i<n; i++) {
		scanf("%d", &cnt[i]);
		int a, x, y, m;
		scanf("%d%d%d%d", &a, &x, &y, &m);

		arr[i].resize(cnt[i]);
		arr[i][0] = a;
		for (int j = 1; j<cnt[i]; j++)
			arr[i][j] = (int64(arr[i][j-1]) * x + y) % m;

		szsum += cnt[i];
	}

/*	for (int i = 0; i<n; i++) {
		for (int j = 0; j<cnt[i]; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}*/

	if (szsum <= 200000) {
		for (int i = 0; i<n; i++)
			active.insert(make_pair(arr[i][0], i));

		int last = -1;
		int ans = -1;
		while (1) {
			set<pii>::iterator it = active.lower_bound(pii(last, -1));
			if (it == active.end()) {
				ans++;
				it = active.begin();
			}
			if (it == active.end()) break;
			int best = it->second;
    
			last = arr[best][curr[best]];
			active.erase(pii(arr[best][curr[best]], best));
			curr[best]++;
			if (curr[best] < cnt[best])
				active.insert(pii(arr[best][curr[best]], best));
    
			if (sol.size() < 210000)
				sol.push_back(make_pair(last, best+1));
		}
    
		printf("%d\n", ans);
		if (sol.size() <= 200000) {
			for (int i = 0; i<sol.size(); i++) printf("%d %d\n", sol[i].first, sol[i].second);
		}
	}
	else {
		int ans = 0;
		for (int i = 0; i<n; i++) {
			int bad = 0;
			for (int j = 1; j<cnt[i]; j++)
				if (arr[i][j] < arr[i][j-1])
					bad++;
			ans = max(ans, bad);
		}
    
		printf("%d\n", ans);
	}

	return 0;
}