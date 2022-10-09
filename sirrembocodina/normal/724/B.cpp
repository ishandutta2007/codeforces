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

int A[100][100];
int n, m;

bool possible(int *A, int a, int b, int x, int y) {
	bool ok = true;
	swap(A[a], A[b]);
	swap(A[x], A[y]);
	forn (i, m - 1) {
		if (A[i] > A[i + 1]) {
			ok = false;
			break;
		}
	}
	swap(A[x], A[y]);
	swap(A[a], A[b]);
	return ok;
}

int main() {
	cin >> n >> m;
	forn (i, n) {
		forn (j, m) {
			cin >> A[i][j];
		}
	}
	forn (i, m) {
		forn (j, i + 1) {
			bool ok = true;
			forn (k, n) {
				bool was = false;
				forn (x, m) {
					forn (y, x + 1) {
						if (possible(A[k], i, j, x, y)) {
							was = true;
							break;
						}
						if (possible(A[k], x, y, i, j)) {
							was = true;
							break;
						}
					}
					if (was) {
						break;
					}
				}
				if (!was) {
					ok = false;
					break;
				}
			}
			if (ok) {
//				cout << j << " " << i << " ";
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
    return 0;
}