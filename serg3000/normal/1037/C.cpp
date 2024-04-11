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
int main() {
	int n;
	string a, b;
	cin >> n;
	cin >> a;
	cin >> b;
	int i = 0;
	int cnt = 0;
	while (i < n) {
		if (a[i] != b[i]) {
			if (i == n - 1) {
				cnt += 1;
				i++;
				break;
			}
			if (a[i] == b[i + 1] && a[i + 1] == b[i]) {
				cnt++;
				i += 2;
			}
			else {
				cnt++;
				i++;
			}
		}
		else {
			i++;
		}
	}
	cout << cnt;
	return 0;
}