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

	long long a, b;
	cin >> a >> b;
	long long P = 1000000007LL;
	long long x = a * (a + 1) / 2LL;
	x %= P;
	long long y = b * (b - 1) / 2LL;
	y %= P;

	long long A = b * ((x * y) % P);
	A %= P;
	long long B = (a * y) % P;
	cout << (A + B) % P << endl;

	return 0;
}