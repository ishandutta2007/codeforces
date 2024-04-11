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
#define all(a) a.begin(), a.end()
#define sqr(a) ((a) * (a))

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld PI = 3.141592653589793238462643l;

bool p[10000010];

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	int n;
	cin >> n;
	memset(p, -1, sizeof p);
	p[0] = p[1] = 0;
	forn (i, 3200) {
		if (p[i]) {
			for (int j = i * i; j <= 10000010; j += i) {
				p[j] = 0;
			}
		}
	}
	forn (i, 10000010) {
		if (p[i]) {
			int q = i;
			int w = 0;
			while (q) {
				(w *= 10) += q % 10;
				q /= 10;
			}
			if (w != i && p[w]) {
				n--;
				if (!n) {
					cout << i;
					return 0;
				}
			}
		}
	}
	return 0;
}