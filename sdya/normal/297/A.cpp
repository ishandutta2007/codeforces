#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string a, b;
	cin >> a >> b;
	int x = count(a.begin(), a.end(), '1');
	if (x % 2 == 1) {
		++x;
	}
	int y = count(b.begin(), b.end(), '1');
	if (x >= y) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}


	return 0;
}