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
typedef pair<int, ll> i_ll;
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
	vector< vector<int> > ab(n, vector<int>(3));
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &(ab[i][0]), &(ab[i][1]));
		ab[i][2] = i;
	}
	sort(ab.begin(), ab.end());
	vector<int> a(n), b(n), id(n);
	for (int i = 0; i < n; i++) {
		a[i] = ab[i][0];
		b[i] = ab[i][1];
		id[i] = ab[i][2];
	}
	int m; cin >> m;
	vector< vector<int> > cdk(m, vector<int>(4));
	for (int j = 0; j < m; j++) {
		scanf("%d%d%d", &cdk[j][0], &cdk[j][1], &cdk[j][2]);
		cdk[j][3] = j + 1;
	}
	sort(cdk.begin(), cdk.end());
	vector<int> c(m), d(m), k(m), index(m);
	for (int j = 0; j < m; j++) {
		c[j] = cdk[j][0];
		d[j] = cdk[j][1];
		k[j] = cdk[j][2];
		index[j] = cdk[j][3];
	}
	map<ll, stack<i_ll> > mp;
	int j = 0;
	bool flag = true;
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		for (; j < m && c[j] <= a[i]; j++)
			mp[d[j]].push(i_ll(index[j], k[j]));
		map<ll, stack<i_ll> >::iterator it = mp.lower_bound(b[i]);
		if (it == mp.end()) {
			flag = false;
			break;
		}
		stack<i_ll>& st = it->second;
		i_ll& p = st.top();
		ans[id[i]] = p.first;
		p.second--;
		if (p.second == 0) st.pop();
		if (st.empty()) mp.erase(it);
	}
	if (flag) {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++)
			cout << ans[i] << ' ';
		cout << endl;
	}
	else cout << "NO" << endl;
}