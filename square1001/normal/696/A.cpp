#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
map<long long, long long> cost;
int q, tp; long long a, b, w;
int main() {
	cin >> q;
	while (q--) {
		cin >> tp >> a >> b;
		if (tp == 1) {
			cin >> w;
			while (a != b) {
				if (a > b) cost[a] += w, a >>= 1;
				else cost[b] += w, b >>= 1;
			}
		}
		else {
			long long ret = 0;
			while (a != b) {
				if (a > b) ret += cost[a], a >>= 1;
				else ret += cost[b], b >>= 1;
			}
			cout << ret << endl;
		}
	}
	return 0;
}