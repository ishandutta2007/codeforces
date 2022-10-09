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

vector<string> s;

int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << 'a' << endl << 'a' << endl << 'b' << endl << 'b';
		return 0;
	}
	if (n % 2) {
		cout << 'a';
		forn (i, n - 1) {
			cout << (i % 4 < 2 ? 'b' : 'c');
		}
		cout << endl;
		cout << 'a';
		forn (i, n - 1) {
			cout << (i % 4 < 2 ? 'c' : 'b');
		}
		cout << endl;
		forn (i, n - 1) {
			cout << (i % 4 < 2 ? 'y' : 'x');
		}
		cout << 'z';
		cout << endl;
		forn (i, n - 1) {
			cout << (i % 4 < 2 ? 'x' : 'y');
		}
		cout << 'z';
	} else {
		forn (i, n) {
			cout << (i % 4 < 2 ? 'b' : 'c');
		}
		cout << endl;
		forn (i, n) {
			cout << (i % 4 < 2 ? 'c' : 'b');
		}
		cout << endl;
		cout << 'z';
		forn (i, n - 2) {
			cout << (i % 4 < 2 ? 'y' : 'x');
		}
		cout << 'k';
		cout << endl;
		cout << 'z';
		forn (i, n - 2) {
			cout << (i % 4 < 2 ? 'x' : 'y');
		}
		cout << 'k';
		cout << endl;
	}
}