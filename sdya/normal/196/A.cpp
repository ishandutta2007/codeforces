#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cmath>

using namespace std;

const int maxN = 100;
string s;
int a[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		++a[s[i] - 'a'];
	}

	string res = "";
	for (int i = 0; i < n; ++i) {
		for (int j = 25; j >= 0; --j) {
			if (a[j] != 0) {
				res += 'a' + j;
				for (int k = i; k < n; ++k) {
					--a[s[k] - 'a'];
					if (s[k] == 'a' + j) {
						i = k;
						break;
					}
				}
				break;
			}
		}
	}

	cout << res << endl;


	return 0;
}