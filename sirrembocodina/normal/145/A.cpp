#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define mp make_pair
#define fs first
#define sc second
#define pb push_back

typedef long double ld;
typedef long long int64;

string a, b;
char temp[100100];

int main() {
	scanf("%s", &temp);
	a = temp;
	scanf("%s", &temp);
	b = temp;
	int x = 0, y = 0, z = 0, t = 0;
	forn (i, a.size()) {
		if (a[i] == '4') {
			if (b[i] == '4') {
				x++;
			} else {
				y++;
			}
		} else {
			if (b[i] == '4') {
				z++;
			} else {
				t++;
			}
		}
	}
	cout << max(y, z);
}