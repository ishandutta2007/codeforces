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

const int SIZE = 100<<10;

int n;
int arr[SIZE][2];
map<int, int> cc;

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
		for (int j = 0; j<2; j++) {
			scanf("%d", &arr[i][j]);
			cc[arr[i][j]]++;
		}

	vector<int> poss;
	for (map<int, int>::iterator it = cc.begin(); it != cc.end(); it++)
		if (2 * it->second >= n)
			poss.push_back(it->first);

	int ans = 1000000000;
	for (int i = 0; i<poss.size(); i++) {
		int sum = 0;
		for (int j = 0; j<n; j++) if (arr[j][0] == poss[i]) sum++;

		int tres = 0;
		for (int j = 0; j<n; j++) if (2 * sum < n && arr[j][0] != poss[i] && arr[j][1] == poss[i]) {
			sum++;
			tres++;
		}

		if (2 * sum >= n)
			ans = min(ans, tres);
	}
			

	if (ans == 1000000000) printf("-1\n");
	else printf("%d\n", ans);	

	return 0;
}