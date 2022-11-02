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
	cin >> n;
	int a1, b1, c1, a2, b2, c2;
	cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
	if (b1 < a1 && b2 < a2 && c1 < a1 && c2 < a2) {
		cout << "YES";
		return 0;
	}
	if (b1 > a1 && b2 < a2 && c1 > a1 && c2 < a2) {
		cout << "YES";
		return 0;
	}
	if (b1 > a1 && b2 > a2 && c1 > a1 && c2 > a2) {
		cout << "YES";
		return 0;
	}
	if (b1 < a1 && b2 > a2 && c1 < a1 && c2 > a2) {
		cout << "YES";
		return 0;
	}
	cout << "NO";
	return 0;

}