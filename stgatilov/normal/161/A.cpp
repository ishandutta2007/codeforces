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

typedef pair<int, int> pii;

int n, m, x, y;
pii req[1<<20], has[1<<20];


int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for (int i = 0; i<n; i++) {
		pii q;
		scanf("%d", &q.first);
		q.second = i;
		req[i] = q;
	}
	for (int i = 0; i<m; i++) {
		pii q;
		scanf("%d", &q.first);
		q.second = i;
		has[i] = q;
	}

	sort(req, req+n);
	sort(has, has+m);

	vector<pii> ans;
	int j = 0;
	for (int i = 0; i<n; i++) {
		int curr = req[i].first;
		while (j < m && has[j].first < curr - x)
			j++;
		if (j < m && has[j].first <= curr + y) {
			ans.push_back(pii(req[i].second, has[j].second));
			j++;
		}
	}

	printf("%d\n", ans.size());
	for (int i = 0; i<ans.size(); i++)
		printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);

	return 0;
}