#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <memory.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = n - 1; i >= 0; i--)
#define forab(i, a, b) for(int i = a; i < b; i++)
#define fordab(i, a, b) for(int i = b - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define int64 long long       
#define ld long double
#define PI 3.1415926535897932
#define INF 1000000000

string s;

int main() {
	int k, a, b, n;
	cin >> k >> a >> b >> s;
	n = s.size();
	if (n < a * k || b * k < n) {
		cout << "No solution";
		return 0;
	}
	int l = n / k, r = n % k;
	forn (i, k) {
		if (i < r) {
			cout << s.substr(i * (l + 1), l + 1) << endl;
		} else {
			cout << s.substr(i * l + r, l) << endl;
		}
	}
}