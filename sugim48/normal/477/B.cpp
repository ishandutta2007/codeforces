#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
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

int main() {
	int a[] = {1, 2, 3, 5};
	int n, m; cin >> n >> m;
	cout << (n * 6 - 1) * m << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++)
			cout << (i * 6 + a[j]) * m << ' ';
		cout << endl;
	}
}