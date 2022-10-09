#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <list>
#include <stack>
#include <queue>
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
#define sqr(x) ((x) * (x))

typedef long long int64;       
typedef long double ld;

int main() {
	int n;
	cin >> n;
	if (n == 0) {
		cout << -1;
		return 0;
	}
	forn (i, n / 4 + 10) {
		if (n - 4 * i < 0) {
			break;
		}
		if ((n - 4 * i) % 7 == 0) {
			forn (j, i) {
				cout << 4;
			}
			forn (j, (n - 4 * i) / 7) {
				cout << 7;
			}
			return 0;
		}
	}
	cout << -1;
}