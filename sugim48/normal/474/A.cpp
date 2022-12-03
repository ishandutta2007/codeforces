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
	string s = "qwertyuiopasdfghjkl;zxcvbnm,./";
	string c; cin >> c;
	int x = (c == "L" ? 1 : -1);
	string t; cin >> t;
	for (int i = 0; i < t.length(); i++)
		cout << s[s.find(t[i]) + x];
	cout << endl;
}