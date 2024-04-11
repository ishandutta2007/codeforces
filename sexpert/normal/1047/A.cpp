#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int rem = n%3;
	if(rem == 0)
	{
		if(n == 3) cout << "1 1 1" << endl;
		if(n == 6) cout << "2 2 2" << endl;
		if(n > 6) cout << "1 1 " << n - 2 << endl;
	}
	else cout << "1 2 " << n - 3 << endl;
}