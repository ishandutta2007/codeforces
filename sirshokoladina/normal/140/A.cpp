#pragma comment(linker, "/STACK:32000000")
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
	int n, R, r;
	cin >> n >> R >> r;
	if (r > R) {
		cout << "NO";
		return 0;
	}
	if (2 * r > R) {
		if (n > 1) {
			cout << "NO";
			return 0;
		} else {
			cout << "YES";
			return 0;
		}
	}
	ld ang = asinl(ld(r) / ld(R - r));
	if (n * ang > PI) {
		cout << "NO";
	} else {
		cout << "YES";
	}
	return 0;
}