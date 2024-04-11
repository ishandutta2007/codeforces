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
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

int n, s;
int magic;
int arr[32];

int matr[32][32];
bool used[32];
void Solve(int u, int v) {
	if (u == n) {

		int diagsum[2] = {0};
		for (int i = 0; i<n; i++) {
			diagsum[0] += matr[i][i];
			diagsum[1] += matr[n-1-i][i];
		}
		if (diagsum[0] != magic || diagsum[1] != magic) return;

		for (int i = 0; i<n; i++) {
			int colsum = 0;
			for (int j = 0; j<n; j++) colsum += matr[j][i];
			if (colsum != magic) return;
		}

		printf("%d\n", magic);
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++)
				printf("%d ", matr[i][j]);
			printf("\n");
		}
		exit(0);
	}

	if (v == n) {
		int rowsum = 0;
		for (int i = 0; i<n; i++) rowsum += matr[u][i];
		if (rowsum == magic)
			Solve(u+1, 0);
		return;
	}

	for (int i = 0; i<s; i++) if (!used[i]) {
		used[i] = true;
		matr[u][v] = arr[i];
		Solve(u, v+1);
		used[i] = false;
	}
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	s = n*n;
	for (int i = 0; i<s; i++) scanf("%d", &arr[i]);
	random_shuffle(arr, arr+s);
	random_shuffle(arr, arr+s);

	int sum = 0;
	for (int i = 0; i<s; i++) sum += arr[i];
	magic = sum / n;

	Solve(0, 0);

	return 0;
}