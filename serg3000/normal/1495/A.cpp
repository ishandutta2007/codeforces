#include <fstream>
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
#include <fstream>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("vpt")
#define ll long long
#define x first
#define y second
#define res resize
#define pb push_back
#define rall(v) v.rbegin(), v.rend()
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define firn(i, n) for (int i = 1; i < (int)n; i++)
#define all(v) v.begin(), v.end()
mt19937 rnd(time(nullptr));
#define int long long
using namespace std;

signed main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int t;
	cin >> t;
	forn(q, t) {
		int n;
		cin >> n;
		vector<int>a;
		vector<int>b;
		forn(i, 2 * n) {
			int x, y;
			cin >> x >> y;
			if (x == 0) {
				a.push_back(abs(y));
			}
			else {
				b.push_back(abs(x));
			}
		}
		double z = 0;
		sort(all(a));
		sort(all(b));
		forn(i, n) {
			z += sqrt(a[i] * a[i] + b[i] * b[i]);
		}
		cout.precision(20);
		cout << z << '\n';
	}
	return 0;
}