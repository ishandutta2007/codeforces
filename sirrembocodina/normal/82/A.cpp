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
	n--;
	s.resize(5);
	s[0] = "Sheldon";
	s[1] = "Leonard";
	s[2] = "Penny";
	s[3] = "Rajesh";
	s[4] = "Howard";
	int p = 1, sum = 0;
	for (; sum + p * 5 <= n; p *= 2) {
		sum += p * 5;
	}
	cout /*<< sum << " " << p << " " */<< s[(n - sum) / p];
}