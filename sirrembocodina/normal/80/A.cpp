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

vector<int> a;

int main() {
	int n, m;
	cin >> n >> m;
	bool p = true;
	forab (i, 2, m) {
		if (m % i == 0) {
			p = false;
			break;
		}
	}
	if (!p) {
		cout << "NO";
		return 0;
	}
	bool yes = true;
	forab (i, n + 1, m) {
		bool p1 = true;
		forab (j, 2, i) {
			if (i % j == 0) {
				p1 = false;
				break;
			}
		}
		if (p1) {
			yes = false;
			break;
		}
	}
	cout << (yes ? "YES" : "NO");
}