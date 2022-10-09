#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define pb push_back
#define fs first
#define sc second
#define mp make_pair

typedef long long int64;

int a[100100];

int main() {
	int n;
	scanf("%d", &n);
	bool none = false;
	forn (i, n) {
		scanf("%d", &a[i]);
		if (a[i] != 1) {
			none = true;
		}
	}
	if (!none) {
		forn (i, n - 1) {
			printf("1 ");
		}
		printf("2");
		return 0;
	}
	sort(a, a + n);
	printf("1 ");
	forn (i, n - 1) {
		printf("%d ", a[i]);
	}
}