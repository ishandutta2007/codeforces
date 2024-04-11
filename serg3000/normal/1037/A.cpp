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
	int x = 1, c = 0;
	while (n > 0) {
		c++;
		n /= 2;
	}
	cout << c;
	return 0;
}