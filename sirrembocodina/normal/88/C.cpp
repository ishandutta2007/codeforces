#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <list>
#include <stack>
#include <queue>
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
#define sqr(x) ((x) * (x))

typedef long long int64;       
typedef long double ld;

vector<int64> x, y;

int main() {
	int64 a, b;
	cin >> a >> b;
	int64 i = 1, j = 1, ansa = 0, ansb = 0, last = 0;
	while (i <= b) {
//		cerr << last << " " << a * i << " " << b * j << endl;
		if (i * a < j * b) {
			ansa += i * a - last;
			last = i * a;
			i++;
		} else if (i * a > j * b) {
			ansb += j * b - last;
			last = j * b;
			j++;
		} else {
			if (a > b) {
				ansa += i * a - last;
			} else {
				ansb += j * b - last;
			}
			last = i * a;
			i++;
			j++;
		}
	}
	if (ansa < ansb) {
		cout << "Masha";
	} else if (ansa > ansb) {
		cout << "Dasha";
	} else {
		cout << "Equal";
	}
}