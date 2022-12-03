#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
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
	int N, M; cin >> N >> M;
	set<int> st;
	while (N--) {
		int a; scanf("%d", &a);
		st.insert(a);
	}
	vector<int> ans;
	for (int x = 1; x <= M; x++)
		if (!st.count(x)) {
			M -= x;
			ans.push_back(x);
		}
	cout << ans.size() << endl;
	for (int x: ans) printf("%d ", x);
	cout << endl;
}