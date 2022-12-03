#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <complex>
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
struct edge { int v; ll w; };

int MOD = 1000000007;

void dfs(int N, int Q, vector<string>& s, vector<string>& t, string x, vector<string>& v) {
	if (x.length() == N) {
		v.push_back(x);
		return;
	}
	for (int k = 0; k < Q; k++)
		if (t[k][0] == x[0])
			dfs(N, Q, s, t, s[k] + x.substr(1), v);
}

int main() {
	int N, Q; cin >> N >> Q;
	vector<string> s(Q), t(Q);
	for (int k = 0; k < Q; k++)
		cin >> s[k] >> t[k];
	vector<string> v;
	dfs(N, Q, s, t, "a", v);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	cout << v.size() << endl;
}