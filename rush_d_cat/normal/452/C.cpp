#include <bits/stdc++.h>
using namespace std;
int n, m;
typedef long long LL;
int main() {
	cin >> n >> m;
	if (n == 1 && m == 1) {
		return !printf("1\n");
	}
	LL denom = n * n;
	double p = 1.0 * (n - 1) * n / (1.0 * n * m * (n * m - 1) );
	//printf("# %.5f\n", p);
	double numer = 1.0 + m * (m - 1) * p;
	//printf("# %.5f\n", numer);
	numer *= n;
	printf("%.10f\n", numer / denom);

}
/*
C(n * m - 2, n - 2)

(n+1)n



1/6  4
5/6  1
(n * m) (n* m - 1)

AA  1/6  4 + 0
BB  1/6  0 + 4
AB  2/3  1 + 1


A1A1: 1/2
A2A2: 

C(n * m, n)
*/