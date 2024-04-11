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

string s[6];

string f(string s) {
	string res = "";
	forv (i, s) {
		char c = s[i];
		if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
			if ('A' <= c && c <= 'Z') {
				res += (c - 'A' + 'a');
			} else {
				res += c;
			}
		}
	}
	return res;
}

int main() {
	string x, y, z;
	cin >> x >> y >> z;
	x = f(x);
	y = f(y);
	z = f(z);
	s[0] = x + y + z;
	s[1] = x + z + y;
	s[2] = y + x + z;
	s[3] = y + z + x;
	s[4] = z + x + y;
	s[5] = z + y + x;
	int n;
	cin >> n;
	forn (i, n) {
		string t;
		cin >> t;
		t = f(t);
		bool ok = false;
		forn (j, 6) {
			if (s[j] == t) {
				ok = true;
			}
		}
		cout << (ok ? "ACC" : "WA") << endl;
	}
}