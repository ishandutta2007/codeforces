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
int matr[128][128];
bool used[128];
int arr[128];

int main() {
#ifdef _CRT_SECURE_NO_DEPRECATE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	memset(matr, 63, sizeof(matr));
	for (int i = 0; i<n; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--;  b--;
		matr[a][b] = c;
	}
	int curr = 0;
	for (int t = 0; t<n; t++) {
		used[curr] = true;
		arr[t] = curr;
		int j;
		for (j = 0; j<n; j++) if ((matr[curr][j] < 10000 || matr[j][curr] < 10000) && !used[j]) break;
		curr = j;
	} while (curr < n);
	arr[n] = arr[0];
//	for (int i = 0; i<n; i++) printf("%d ", arr[i]); printf("\n");
	
	int ans = 1000000000;
	for (int r = 0; r<2; r++) {
		int tres = 0;
		for (int j = 0; j<n; j++) if (matr[arr[j]][arr[j+1]] > 10000) {
			tres += matr[arr[j+1]][arr[j]];
		}
		if (ans > tres) ans = tres;

		reverse(arr, arr+n);
		arr[n] = arr[0];
	}
	printf("%d\n", ans);
	return 0;
}