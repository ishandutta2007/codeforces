#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n, k;
	cin >> n >> k;
	long long h = k/n;
	if(h*n < k) h++;
	cout << h << endl;
}