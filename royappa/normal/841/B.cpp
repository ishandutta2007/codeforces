#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n;
	cin >> n;
	int numEven = 0, numOdd = 0;
	LL sum = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		numEven += 1-x%2;
		numOdd += x%2;
		sum += x;
	}
	if (numEven == n) {
		cout << "Second";
	}
	else {
		cout << "First";
	}
	cout << endl;

	exit(0);
}