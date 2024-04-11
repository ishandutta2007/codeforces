#include<bits/stdc++.h>

using namespace std;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, s;

	cin >> n >> s;

	long long res = s/n;

	if(s%n)
		res++;

	cout << res << "\n";

	return 0;
}