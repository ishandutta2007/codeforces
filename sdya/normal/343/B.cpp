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
#include <stack>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
char s[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	gets(s);
	int n = strlen(s);

	stack < char > p;
	for (int i = 0; i < n; ++i) {
		if (p.empty() || p.top() != s[i]) {
			p.push(s[i]);
		} else {
			p.pop();
		}
	}

	if (p.empty()) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}


	return 0;
}