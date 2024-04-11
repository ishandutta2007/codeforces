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

int n, k;
char matr[8][8];

int s[8];
char res[8][256][256];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &k);
	k--;

	s[0] = n;
	for (int i = 0; i<n; i++) {
		scanf("%s", matr[i]);
		strcpy(res[0][i], matr[i]);
	}

	for (int i = 0; i<k; i++) {
		s[i+1] = s[i] * n;
		for (int u = 0; u<s[i]; u++)
			for (int v = 0; v<s[i]; v++) {
				for (int x = 0; x<n; x++)
					for (int y = 0; y<n; y++)
						res[i+1][u*n+x][v*n+y] = (res[i][u][v]=='*' ? '*' : matr[x][y]);
			}
	}

	for (int i = 0; i<s[k]; i++) {
		for (int j = 0; j<s[k]; j++) printf("%c", res[k][i][j]);
		printf("\n");
	}

	return 0;
}