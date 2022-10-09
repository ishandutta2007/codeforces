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
#define ford(i, n) for (int i = n - 1; i >= 0 ; i--)
#define forv(i, a) for (int i = 0; i < (int)(a.size()); i++)
#define forab(i, a, b) for (int i = a; i < (int)(b); i++)
#define fordab(i, a, b) for (int i = b - 1; i >= (int)(a); i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pi 3.1415926535897932
#define all(a) a.begin(), a.end()
#define eps 0.000000005

typedef long long int64;       
typedef long double ld;

string s;
int n, k;

void dec() {
	k--;
	if (k == 0) {
		cout << s.substr(1, n);
		exit(0);
	}
}

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	cin >> n >> k;
	cin >> s;
	if (!k) {
		cout << s;
		exit(0);
	}
	s = '1' + s + '1';
	forab (i, 1, n) {
		if (s[i] != '4' || s[i + 1] != '7') {
			continue;
		}
		if (i % 2 && s[i + 2] == '7') {
			if (k % 2) {
				s[i + 1] = '4';
			}
			cout << s.substr(1, n);
			exit(0);
		}
		if (i % 2 == 0 && s[i - 1] == '4') {
			if (k % 2) {
				s[i] = '7';
			}
			cout << s.substr(1, n);
			exit(0);
		}
		if (i % 2) {
			s[i + 1] = '4';
			dec();
		} else {
			s[i] = '7';
			dec();
		}
	}
	cout << s.substr(1, n);
}