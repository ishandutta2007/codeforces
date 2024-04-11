#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
#include<iostream>
#include<ctime>
#include<iomanip>
#include<cassert>
#include<memory>
#include<string>
#include<string.h>
#include<math.h>

using namespace std;

typedef double ld;
typedef long long li;
typedef pair<int, int> pt;

li a, b;

void read() {
	cin >> a >> b;
}

void solve() {
	li ans = 1;
	for (li i = a + 1; i <= b; ++i) {
		ans = ans * (i % 10) % 10;
		if (ans == 0)
			break;
	}
	cout << ans << endl;
}

int main() {

	srand(time(NULL));

	read();
	solve();

	return 0;
}