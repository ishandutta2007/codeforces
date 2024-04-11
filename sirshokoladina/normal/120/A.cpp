#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <deque>
#include <queue>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define ford(i,n) for (int i = (int)(n) - 1; i >= 0; i--)

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	string s;
	int n;
	cin >> s >> n;
	if ((s[0] == 'f') ^ (n == 1)) {
		cout << 'R';
	} else {
		cout << 'L';
	}
}