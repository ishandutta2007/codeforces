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

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define ford(i,n) for(int i=n-1;i>=0;i--)
#define forab(i,a,b) for(int i=a;i<b;i++)
#define fordab(i,a,b) for(int i=b-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define int64 long long       
#define ld long double
#define pi 3.1415926535897932


int main() {
	int n, m, x;
	cin >> n >> m >> x;
	x--;
	n -= 2 * x;
	m -= 2 * x;
	if (n <= 0 || m <= 0) {
		cout << 0;
		return 0;
	}
	if (n == 1) {
		cout << (m + 1) / 2;
		return 0;
	}
	if (m == 1) {
		cout << (n + 1) / 2;
		return 0;
	}
	cout << n + m - 2;
}