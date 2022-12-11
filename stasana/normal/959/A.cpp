#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef int_fast64_t ll;
typedef long double ld;

void start() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
}

int main() {
	start();
	int n;
	cin >> n;
	if (n % 2 == 0) {
		cout << "Mahmoud" << endl;
	}
	else {
		cout << "Ehab" << endl;
	}
	return 0;
}