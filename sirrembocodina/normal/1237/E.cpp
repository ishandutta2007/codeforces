#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	if (n == 2) {
		cout << 1 << endl;
		return 0;
	}
	if (n == 3) {
		cout << 0 << endl;
		return 0;
	}
	int a = 4, b = 5;
	while (n > a && n > b) {
//		cout << a << " " << b << endl;
		int na, nb;
		nb = a + 1 + a;
		na = a + 1 + b;
		a = na;
		b = nb;
	}
	if (n == a || n == b) {
		cout << 1 << endl;
	} else {
		cout << 0 << endl;
	}
}