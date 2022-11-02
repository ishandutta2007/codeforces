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

const int maxN = 210000;
const int maxL = 25;
char s[maxN][maxL];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	set < pair < int, string > > S;
	map < string, int > M;

	int n;
	scanf("%d", &n);

	int value = -1;
	for (int i = 0; i < n; ++i) {
		scanf("%s", &s[i]);
		string current = s[i];
		int oldValue = M[current];
		S.erase(make_pair(oldValue, current));
		M[current] = --value;
		S.insert(make_pair(value, current));
	}

	for (set < pair < int, string > > ::iterator it = S.begin(); it != S.end(); ++it) {
		printf("%s\n", it->second.c_str());
	}

	return 0;
}