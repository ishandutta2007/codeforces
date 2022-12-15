#include<bits/stdc++.h>

using namespace std;

int main ()
{
	int n, m, k;

	cin >> n >> m >> k;

	int res = 0;

	for(int i = 0; i < k; i++)
		res += 2*(n-4*i)+2*(m-4*i)-4;

	cout << res << endl;

	return 0;
}