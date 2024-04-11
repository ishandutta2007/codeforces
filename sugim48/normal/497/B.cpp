#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	vector<int> sum1(n + 1), sum2(n + 1);
	for (int i = 1; i <= n; i++) {
		sum1[i] = sum1[i - 1];
		sum2[i] = sum2[i - 1];
		if (a[i - 1] == 1) sum1[i]++;
		else sum2[i]++;
	}
	vector<i_i> ans;
	for (int t = 1; t <= n; t++) {
		int i = 0, s1 = 0, s2 = 0, last;
		while (i < n) {
			int i1 = lower_bound(sum1.begin(), sum1.end(), sum1[i] + t) - sum1.begin();
			int i2 = lower_bound(sum2.begin(), sum2.end(), sum2[i] + t) - sum2.begin();
			if (i1 < i2) {
				s1++;
				last = 1;
			}
			else if (i1 > i2) {
				s2++;
				last = 2;
			}
			i = min(i1, i2);
		}
		if (i > n || s1 == s2) continue;
		if (last == 1 && s1 < s2) continue;
		if (last == 2 && s1 > s2) continue;
		ans.push_back(i_i(max(s1, s2), t));
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int j = 0; j < ans.size(); j++)
		cout << ans[j].first << ' ' << ans[j].second << endl;
}