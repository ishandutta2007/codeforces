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
	
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 1) {
			cout << "HARD";
			return 0;
		}
	}
	cout << "EASY";
	return 0;
}