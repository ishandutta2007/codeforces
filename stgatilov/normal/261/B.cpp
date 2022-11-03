//#pragma comment(linker, "/STACK:20000000")
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

const int SIZE = 54;

int n, w;
int arr[SIZE];
double res[SIZE][SIZE][2][SIZE][SIZE];
double fact[SIZE];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	for (int i = 0; i<n; i++) scanf("%d", &arr[i]);
	scanf("%d", &w);

	res[0][0][0][0][0] = 1;
	for (int i = 0; i<n; i++)
		for (int a = 0; a<=n; a++)
			for (int b = 0; b<2; b++)
				for (int s = 0; s<=w; s++)
					for (int t = 0; t<SIZE; t++) {
						double tres = res[i][a][b][s][t];
						if (tres == 0.0) continue;
						res[i+1][a][b][s][t] += tres;
						if (s + arr[i] <= w) res[i+1][a+1][b][s+arr[i]][t] += tres;
						if (b == 0) res[i+1][a][b+1][s][t+arr[i]] += tres;
					}

	fact[0] = 1.0;
	for (int i = 1; i<SIZE; i++) fact[i] = i * fact[i-1];

	double ans = 0.0, chk = 0.0;

	for (int a = 0; a<n; a++)
		for (int s = 0; s<=w; s++)
			for (int t = w-s+1; t<SIZE; t++) {
				double tres = res[n][a][1][s][t];
				if (tres == 0.0) continue;
				double tt = tres * fact[a] * fact[n-1-a] / fact[n];
				ans += tt * a;
				chk += tt;
			}
	for (int s = 0; s<=w; s++) {
		double tres = res[n][n][0][s][0];
		if (tres == 0.0) continue;
		double tt = tres * fact[n] / fact[n];
		ans += tt * n;
		chk += tt;
	}
	
	printf("%0.15lf\n", ans);
//	printf("%0.15lf\n", chk);

	return 0;
}