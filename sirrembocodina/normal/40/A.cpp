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
	int x, y;
	cin >> x >> y;
	if (sqrt(x * x + y * y) - floor(sqrt(x * x + y * y)) < 0.000001 || x * y == 0) {
		cout << "black";
		return 0;
	}
	int l = int(floor(sqrt(x * x + y * y)));
	// cout << l << endl;
	if ((x * y > 0) != (l % 2)) {
		cout << "black";
	} else {
		cout << "white";
	}
}