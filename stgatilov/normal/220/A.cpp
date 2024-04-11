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

const int SIZE = 1<<20;
int n;
int arr[SIZE];

int main() {
#ifdef _CRT_SECURE_NO_DEPRECATE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 0; i<n; i++) scanf("%d", &arr[i]);

	vector<int> bad;
	for (int i = 1; i<n; i++) if (arr[i] < arr[i-1]) {
		bad.push_back(i);
		bad.push_back(i-1);
	}
	sort(bad.begin(), bad.end());
	bad.resize(unique(bad.begin(), bad.end()) - bad.begin());
	vector<int> tmp;

	if (bad.size() > 8) printf("NO\n");
	else {
		bool ans = (bad.size() == 0);
		for (int i = 0; i<bad.size(); i++) {
			for (int j = 0; j<n; j++) {
				swap(arr[bad[i]], arr[j]);

				tmp = bad;
				tmp.push_back(j-1);
				tmp.push_back(j);
				tmp.push_back(j+1);

				bool ok = true;
				for (int u = 0; u<tmp.size(); u++) {
					if (tmp[u] < 0 || tmp[u] >= n) continue;
					int q = tmp[u];
					if (q > 0 && arr[q] < arr[q-1]) ok = false;
					if (q+1 < n && arr[q+1] < arr[q]) ok = false;
				}

				swap(arr[bad[i]], arr[j]);
				if (ok) {
					ans = true;
//					printf("%d %d\n", bad[i], j);
				}
			}

		}
		printf("%s\n", ans ? "YES" : "NO");
	}
		
	return 0;
}