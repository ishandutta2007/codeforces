#include <bits/stdc++.h>

using namespace std;



int n, m;



int main() {

	scanf("%d %d", &n, &m);

	n = min(30, n);

	n = 1 << n;

	printf("%d\n", m % n);



	return 0;

}