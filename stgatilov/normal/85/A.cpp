#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

int n;
char matr[4][128];

char GetColor(int i, int j) {
	return 'a' + (4*j+i)%26;
}

void Draw(int i1, int j1, int i2, int j2) {
	char c = GetColor(i1, j1);
	matr[i1][j1] = matr[i2][j2] = c;
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);

	if (n & 1) {
		Draw(0, 0, 1, 0);
		Draw(2, n-1, 3, n-1);
	}
	else {
		Draw(1, 0, 2, 0);
		Draw(1, n-1, 2, n-1);
	}

	for (int i = 0; i<4; i++) {
		for (int j = 0; j<n; ) {
			if (matr[i][j]) j++;
			else {
				Draw(i, j, i, j+1);
				j+=2;
			}
		}
		matr[i][n] = 0;
	}
	 
	for (int i = 0; i<4; i++) printf("%s\n", matr[i]);

	return 0;
}