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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

long long n;
char c;

string s = "fedabc";

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	
	scanf("%I64d%c", &n, &c);

	long long m = n / 4;
	if (n % 4 == 0) {
		--m;
	}

	long long t = 16 * m;

	n -= 4 * m;
	for (int i = 0; i < s.size(); ++i) {
		if (c == s[i]) {
			t += i + 1;
		}
	}

	if (n == 2 || n == 4) {
		t += 7;
	}

	cout << t << endl;

	return 0;
}