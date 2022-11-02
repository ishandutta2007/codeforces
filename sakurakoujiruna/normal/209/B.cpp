#include <bits/stdc++.h>
using namespace std;

long long a[3];

int main() {
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	if((a[1] - a[0]) & 1)
		cout << a[2] << '\n';
	else
		cout << a[1] << '\n';
}