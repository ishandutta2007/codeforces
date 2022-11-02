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
	if (n % 3 == 0 || n % 3 == 1) {
		cout << 1 << " " << 1 << " " << n - 2;
	}
	else {
		cout << 1 << " " << 2 << " " << n - 3;
	}




	return 0;
	
}