#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <cassert>
 
using namespace std;
 
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sqr(a) ((a) * (a))
#define all(a) a.begin(), a.end()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;

const ld pi = 3.1415926535897932384626433832795l;

const ll mod = 1000000007;
const int K = 330;

int main() {
	long long n, ans;
	char c;
	cin >> n >> c;
	--n;
	ans += (n / 4) * 16;
	n %= 4;
	if (n >= 2) {
		n -= 2;
	}
	if (n % 2) {
		ans += 7;
	}
	if (c == 'f') {
		ans += 0;
	} else if (c == 'e') {
		ans += 1;
	} else if (c == 'd') {
		ans += 2;
	} else if (c == 'a') {
		ans += 3;
	} else if (c == 'b') {
		ans += 4;
	} else if (c == 'c') {
		ans += 5;
	}
	cout << ans + 1;
    return 0;
}