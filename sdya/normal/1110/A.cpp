#define _CRT_SECURE_NO_WARNINGS
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
#include <unordered_set>
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int b, k;
	cin >> b >> k;
	int res = 0;
	for (int i = 0; i < k; ++i) {
	    int x;
	    cin >> x;
	    res = res * b + x;
	    res %= 2;
	}
	cout << (res == 0 ? "even" : "odd") << endl;

	return 0;
}