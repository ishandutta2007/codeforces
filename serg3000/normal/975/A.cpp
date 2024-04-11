#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
int main() {
	int n;
	set<int> sett;
	cin >> n;
	vector<int> step(26);
	long long z = 1;
	for (int i = 0; i < 26; i++) {
		step[i] = z;
		z *= 2;
	}
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		vector<int>b(26, 0);
		for (int j = 0; j < (int)a.size(); j++) {
			if (b[a[j] % 26] == 0) {
				b[a[j] % 26] = 1;
			}
		}
		long long x = 0;
		for (int j = 0; j < 26; j++) {
			x += b[j] * step[j];
		}
		sett.emplace(x);
	}

	cout << (int)sett.size();
	return 0;
}