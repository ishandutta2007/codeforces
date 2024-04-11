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
	vector<int> a(10);
	for (int i = 0; i < 6; i++) {
		int l; cin >> l;
		a[l]++;
	}
	bool flag = false;
	for (int l = 1; l <= 9; l++) {
		if (a[l] >= 4) {
			a[l] -= 4;
			flag = true;
		}
	}
	if (!flag) {
		cout << "Alien" << endl;
		return 0;
	}
	for (int l = 1; l <= 9; l++) {
		if (a[l] == 2) {
			cout << "Elephant" << endl;
			return 0;
		}
	}
	cout << "Bear" << endl;
}