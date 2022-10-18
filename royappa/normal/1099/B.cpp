#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n;
	cin >> n;

	int a = 1, b = 1;
	while (a*b < n) {
		if (a < b) a++;
		else b++;
	}
	cout << a+b << endl;
	exit(0);
}