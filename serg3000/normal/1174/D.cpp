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
using namespace std;
#define int long long
signed main() {
	int n, x;
	cin >> n >> x;
	vector<int>a;
	int z = 1;
	for (int i = 0; i < n; i++) {
		z *= 2;
	}
	vector<int>b(z + 1);
	if (x >= z) {
		x = 0;
	}
	b[x] = 1;
	b[0] = 1;
	a.push_back(x);
	int k = x;
	for (int i = 1; i < z; i++) {
		if (b[i] == 0) {
			a.push_back(i ^ k);
			b[i] = 1;
			k = i;
			a.push_back(x);
			k ^= x;
			b[k] = 1;
		}
	}
	cout << (int)a.size() / 2 << '\n';
	for (int i = 1; i < (int)a.size(); i += 2) {
		cout << a[i] << " ";
	}
	return 0;
}