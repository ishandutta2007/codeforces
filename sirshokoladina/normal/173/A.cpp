#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <memory.h>
#include <ctime>
#include <cctype>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define mp make_pair
#define fs first
#define sc second
#define pb push_back

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld PI = 3.141592653589793238462643l;

int x[1000010], y[1000010];

int num[256];

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	num['R'] = 0;
	num['S'] = 1;
	num['P'] = 2;
	int n;
	string s, t;
	cin >> n >> s >> t;
	int m = s.size() * t.size();
	x[0] = y[0] = 0;
	forn (i, m) {
		x[i + 1] = x[i];
		y[i + 1] = y[i];
		int a = num[s[i % s.size()]], b = num[t[i % t.size()]];
		if (a != b) {
			if ((a + 1) % 3 == b) {
				y[i + 1]++;
			} else {
				x[i + 1]++;
			}
		}
	}
	cout << (n / m) * x[m] + x[n % m] << ' ';
	cout << (n / m) * y[m] + y[n % m] << endl;
	return 0;
}