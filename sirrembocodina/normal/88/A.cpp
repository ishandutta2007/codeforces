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

map<string, int> m;

int main() {
	m["C"] = 0;
	m["C#"] = 1;
	m["D"] = 2;
	m["D#"] = 3;
	m["E"] = 4;
	m["F"] = 5;
	m["F#"] = 6;
	m["G"] = 7;
	m["G#"] = 8;
	m["A"] = 9;
	m["B"] = 10;
	m["H"] = 11;
	string x[3];
	cin >> x[0] >> x[1] >> x[2];
	forn (i, 3) {
		forn (j, 3) {
			if (i == j) {
				continue;
			}
			forn (k, 3) {
				if (i == k || j == k) {
					continue;
				}
				if ((m[x[i]] + 4) % 12 == m[x[j]] && (m[x[j]] + 3) % 12 == m[x[k]]) {
					cout << "major";
					return 0;
				}
				if ((m[x[i]] + 3) % 12 == m[x[j]] && (m[x[j]] + 4) % 12 == m[x[k]]) {
					cout << "minor";
					return 0;
				}
			}
		}
	}
	cout << "strange";
}