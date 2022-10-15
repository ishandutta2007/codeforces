#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

#define Inf 2147483647

#define Swap(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define Min(x, y) ((x) < (y) ? (x) : (y))
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Abs(x) ((x) < 0 ? -(x) : (x))

int a, b, n;
bool flag;

int main() {
	cin >> a >> b >> n;
	if (a < b) {
		flag = true;
	} else {
		flag = false;
	}
	int c = a + b;
	for (int i = 1; i <= c; i++) {
		if (flag) {
			printf("1");
			b--;
		} else {
			printf("0");
			a--;
		}
		if (n == 1) {
			if (a == 0 || b == 0) {
				n--;
				flag = !flag;
			}
		} else if (n > 0) {
			n--;
			flag = !flag;	
		}
	}
	return 0;
}

// By Sooke.
// CF1003B Binary String Constructing.