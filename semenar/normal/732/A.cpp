#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <math.h>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, r;
	cin >> n >> r;
	for (int i = 1; i < 10; i++) {
		if (((n*i) % 10) == r || ((n*i) % 10) == 0) {
			cout << i;
			return 0;
		}
	}
	cout << 10;
	return 0;
}