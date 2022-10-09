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

int main() {
	int n, a, b, c, ans = 0;
	cin >> n >> a >> b >> c;
	n *= 2;
	forn (i, b + 1) {
		forn (j, c + 1) {
			if (i * 2 + j * 4 > n) {
				break;
			}
			ans += n - i * 2 - j * 4 <= a;
		}
	}
	cout << ans;
}