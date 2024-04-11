#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n;
	cin >> n;
	int l = n%10;
	if (l <= 5) {
		cout << n-n%10 << endl;
	}
	else {
		cout << n-n%10+10 << endl;
	}
	exit(0);
}