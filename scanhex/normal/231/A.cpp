#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long 
using namespace std;
int main() 
{
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a + b + c >= 2)
			++cnt;
	}
	cout << cnt;  
}