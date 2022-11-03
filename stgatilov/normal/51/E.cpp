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

const int SIZE = 712;

int n, m;

template<class T> struct Matrix {
	T matr[SIZE][SIZE];

	template<class S> void operator= (const Matrix<S> &other) {
		for (int i = 0; i<n; i++)
			for (int j = 0; j<n; j++)
				matr[i][j] = other.matr[i][j];
	}
};

template<class A, class B, class C, class CAST> void Multiply(const Matrix<A> &a, const Matrix<B> &b, Matrix<C> &r) {
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++) {
			C res = 0;
			for (int u = 0; u<n; u++) res += CAST(a.matr[i][u]) * b.matr[u][j];
			r.matr[i][j] = res;
		}
}

Matrix<int> roads;
Matrix<int> M1, M2, M3;
Matrix<int64> M4;

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &m);
	for (int i = 0; i<m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;  b--;
		roads.matr[a][b] = 1;
		roads.matr[b][a] = 1;
	}

	M1 = roads;
	Multiply<int, int, int, int>(M1, M1, M2);
	Multiply<int, int, int, int>(M1, M2, M3);
	Multiply<int, int, int64, int64>(M1, M3, M4);

	int64 d3 = 0;
	for (int i = 0; i<n; i++) d3 += M3.matr[i][i];

	int64 d5 = 0;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) d5 += int64(M2.matr[i][j]) * M3.matr[j][i];
	}

	int64 d23 = 0;
	for (int i = 0; i<n; i++) d23 += int64(M2.matr[i][i]) * M3.matr[i][i];
	int64 d22 = 0;
	for (int i = 0; i<n; i++) d22 += int64(M2.matr[i][i]) * M2.matr[i][i];

	int64 ans = (d5 + d3*5 - d23*5);

	printf("%I64d\n", ans/10);

	return 0;
}