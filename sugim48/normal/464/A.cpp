#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
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
struct edge { int u, v; ll w; int rev; };

int main() {
	int n, p; string s; cin >> n >> p >> s;
	int i;
	for (i = n - 1; i >= -1; i--) {
		if (i == -1) {
			cout << "NO" << endl;
			return 0;
		}
		bool flag = true;
		for (;;) {
			s[i]++;
			if (s[i] - 'a' == p) {
				flag = false;
				break;
			}
			if (i - 1 >= 0 && s[i - 1] == s[i]) continue;
			if (i - 2 >= 0 && s[i - 2] == s[i]) continue;
			break;
		}
		if (flag) break;
	}
	for (i++; i < n; i++) {
		s[i] = 'a' - 1;
		for (;;) {
			s[i]++;
			if (i - 1 >= 0 && s[i - 1] == s[i]) continue;
			if (i - 2 >= 0 && s[i - 2] == s[i]) continue;
			break;
		}
	}
	cout << s << endl;
}