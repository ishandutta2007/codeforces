#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, x, y;

	cin >> n >> x >> y;

	if(max(abs(1-x),abs(1-y)) <= max(abs(n-x), abs(n-y)))
		cout << "White\n";
	else
		cout << "Black\n";

	return 0;
}