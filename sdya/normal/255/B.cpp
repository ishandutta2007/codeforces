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

const int maxN = 1100000;
char s[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%s", &s);
	int n = strlen(s);
	int a = count(s, s + n, 'x');
	int b = count(s, s + n, 'y');

	if (a > b) {
		puts(string(a - b, 'x').c_str());
	} else {
		puts(string(b - a, 'y').c_str());
	}


	return 0;
}