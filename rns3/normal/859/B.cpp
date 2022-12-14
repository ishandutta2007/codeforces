#include <bits/stdc++.h>

using namespace std;



int main() {

	//freopen("r.in", "r", stdin);

	int n;

	scanf("%d", &n);

	int m = sqrt(4 * n - 1) + 1;

	m *= 2;

	printf("%d\n", m);



	return 0;

}