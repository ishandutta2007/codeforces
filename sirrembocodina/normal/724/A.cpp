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

char s[100];

int main() {
	int a, b;
	cin >> s;
	if (s[0] == 'm') {
		a = 0;
	} else if (s[0] == 't' && s[1] == 'u') {
		a = 1;
	} else if (s[0] == 'w') {
		a = 2;
	} else if (s[0] == 't') {
		a = 3;
	} else if (s[0] == 'f') {
		a = 4;
	} else if (s[0] == 's' && s[1] == 'a') {
		a = 5;
	} else {
		a = 6;
	}
	cin >> s;
	if (s[0] == 'm') {
		b = 0;
	} else if (s[0] == 't' && s[1] == 'u') {
		b = 1;
	} else if (s[0] == 'w') {
		b = 2;
	} else if (s[0] == 't') {
		b = 3;
	} else if (s[0] == 'f') {
		b = 4;
	} else if (s[0] == 's' && s[1] == 'a') {
		b = 5;
	} else {
		b = 6;
	}
	a = (7 + b - a) % 7;
	if (a == 0 || a == 2 || a == 3) {
		cout << "YES";
	} else {
		cout << "NO";
	}
    return 0;
}