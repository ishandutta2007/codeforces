#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;

int main ()
{
	long long l, r;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> l >> r;

	cout << "YES\n";

	for(long long i = l ; i <= r; i += 2)
		cout << i << " " << i+1 << "\n";

	return 0;
}