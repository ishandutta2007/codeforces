#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <list>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
        
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = n - 1 ; i >= 0 ; i--)
#define forv(i, a) for (int i = 0; i < (int)(a.size()); i++)
#define forab(i, a, b) for (int i = a; i < (int)(b); i++)
#define fordab(i, a, b) for (int i = b - 1; i >= (int)(a); i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pi 3.1415926535897932
#define all(a) a.begin(), a.end()

typedef long long int64;       
typedef long double ld;


const int64 p = 1000000007;

int64 power(int64 a, int64 b) {
	int64 twop = 1, res = 1;
	while (twop <= b) {
		if (!(twop & b)) {
			twop *= 2;
			a = (a * a) % p;
			continue;
		}
		res = (res * a) % p;
		twop *= 2;
		a = (a * a) % p;
	}
	return res;
}

int64 dev(int64 a, int64 b) {
	return (a * power(b, p - 2)) % p;
}

int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	int64 res = 1;
	forab (i, n, 2 * n) {
		res = (res * i) % p;
	}
	forab (i, 1, n + 1) {
		res = dev(res, i);
	}
	cout << (res * 2 - n) % p;
	return 0;
}