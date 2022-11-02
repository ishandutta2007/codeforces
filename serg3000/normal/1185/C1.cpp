#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include<unordered_map>
#include <bitset>
#include <random>
#include <ctime>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)
using namespace std;
mt19937 rnd(time(NULL));
#define int long long
signed main() {
	int n, m;
	cin >> n >> m;
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int>b;
	cout << 0 << " ";
	int s = a[0];
	for (int w = 1; w < n; w++) {
		b.push_back(a[w - 1]);
		s += a[w];
		sort(b.begin(), b.end());
		int x = w - 1;
		int z = s - m;
		int ans = 0;
		while (x > -1 && z > 0) {
			z -= b[x];
			x--;
			ans++;
		}
		cout << ans << " ";
	}
	
	return 0;
}