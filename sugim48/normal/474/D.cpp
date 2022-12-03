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
	int t, k; cin >> t >> k;
	vector<ll> fib(100001);
	for (int i = 0; i < k; i++) fib[i] = 1;
	for (int i = k; i <= 100000; i++)
		fib[i] = (fib[i - 1] + fib[i - k]) % 1000000007;
	vector<ll> sum(100001);
	for (int i = 1; i <= 100000; i++)
		sum[i] = (sum[i - 1] + fib[i]) % 1000000007;
	while (t--) {
		int a, b; cin >> a >> b;
		cout << (sum[b] - sum[a - 1] + 1000000007) % 1000000007 << endl;
	}
}