#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <memory.h>
#include <ctime>
#include <cctype>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define mp make_pair
#define fs first
#define sc second
#define pb push_back

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld PI = 3.141592653589793238462643l;

int main() {
	//freopen("input.txt", "rt", stdin)
	//freopen("output.txt", "wt", stdout)
	long long a;
	cin >> a;
	vector<long long> p;
	for (long long b = 2; b * b <= a; b++) {
		while (a % b == 0) {
			p.pb(b);
			a /= b;
		}
	}
	if (a > 1) {
		p.pb(a);
	}
	if (p.size() < 2) {
		cout << "1\n0\n";
		return 0;
	}
	if (p.size() == 2) {
		cout << "2\n";
		return 0;
	}
	cout << "1\n" << p[0] * p[1] << "\n";
	return 0;
}