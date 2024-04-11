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
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define firn(i, n) for (int i = 1; i < (int)n; i++)
#define all(v) v.begin(), v.end()
mt19937 rnd(time(nullptr));
#define int long long
using namespace std;
vector<vector<int>>g;
signed main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	forn(q, t) {
		int n;
		cin >> n;
		string a;
		cin >> a;
		string s;
		int c = 0;
		forn(i, n) {
			if(a[i] == 't'){
				c++;
			}
			else {
				s.push_back(a[i]);
			}
		}
		forn(i, c) {
			s.push_back('t');
		}
		cout << s <<  '\n';
	}
	return 0;
}