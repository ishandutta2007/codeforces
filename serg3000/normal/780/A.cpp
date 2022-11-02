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
struct edge {};
signed main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int>a(2 * n);
	forn(i, 2 * n) {
		cin >> a[i];
	}
	map<int, int>mp;
	int x = 0;
	int z = 0;
	forn(i, 2 * n) {
		if (mp[a[i]] == 0) {
			x++;
		}
		else {
			x--;
		}
		mp[a[i]] = 1;
		z = max(z, x);
	}
	cout << z;
	return 0;
}