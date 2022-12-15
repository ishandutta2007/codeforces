#include<bits/stdc++.h>

using namespace std;

int main ()
{
	int n, p, k;

	cin >> n >> p >> k;

	if(p-k > 1)
		cout << "<< ";

	for(int i = max(1, p-k); i <= p-1; i++)
		cout << i << " ";

	cout << "(" << p << ") ";

	for(int i = p+1; i <= min(p+k, n); i++)
		cout << i << " ";

	if(p+k < n)
		cout << ">>";

	cout << "\n";

	return 0;
}