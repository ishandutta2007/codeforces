#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int cnt[] = {0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 15, 4}; 

int main() {
	int n;
	cin >> n;
	n -= 10;
	if (n < 0 || n > 11) {
		cout << 0 << endl;
	} else {
		cout << cnt[n] << endl;
	}
	
	return 0;
}