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
 
int main() {
	int n, a, b;
	char s[10];
	scanf("%d%s", &n, s);
	if (s[1] < '0' || s[1] > '9') {
		s[1] = '0';
	}
	if (s[3] < '0' || s[3] > '5') {
		s[3] = '0';
	}
	if (s[4] < '0' || s[4] > '9') {
		s[4] = '0';
	}
	if (n == 12) {
		if (s[0] < '0' || s[0] > '1') {
			s[0] = '0';
		}
		if (s[0] == '1' && s[1] > '2') {
			s[0] = '0';
		}
		if (s[1] == '0') {
			s[0] = '1';
		}
	} else {
		if (s[0] < '0' || s[0] > '2') {
			s[0] = '0';
		}
		if (s[0] == '2' && s[1] > '3') {
			s[0] = '0';
		}
	}
	s[2] = ':';
	cout << s;
    return 0;
}