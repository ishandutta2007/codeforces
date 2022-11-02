#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long a, b;
	cin >> a >> b;

	long long res = 0;
	while (b) {
		long long q = a / b;
		res += q;
		a -= q * b;
		swap(a, b);
	}

	cout << res << endl;
	

	return 0;
}