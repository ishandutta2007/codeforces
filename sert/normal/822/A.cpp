#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int f = 1;
	for (int i = 1; i <= min(a, b); i++)
		f *= i;
	cout << f;
	return 0;
}